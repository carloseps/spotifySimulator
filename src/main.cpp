#include <iostream>
#include <string>
#include <sqlite3/sqlite3.h>
#include <SpotifyApiService.hpp>
#include <Track.h>
#include <Player.hpp>
#include <UserDao.hpp>

using namespace std;

SpotifyApiService spotifyApiService;

std::vector<Track> *searchedTracksResult = new std::vector<Track>();

void testConnection()
{
    sqlite3 *db;
    int rc = sqlite3_open("./database/database.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cout << "Falha ao abrir ao banco de dados" << std::endl;
        sqlite3_close(db);
        return;
    }

    std::cout << "Banco de dados aberto com sucesso!" << std::endl;

    std::string sql = "CREATE TABLE IF NOT EXISTS TestTable ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "username VARCHAR(30) NOT NULL,"
                      "email VARCHAR(80),"
                      "password VARCHAR(50) NOT NULL"
                      ");";

    // std::string sql = "CREATE TABLE IF NOT EXISTS spotifySimulator ("
    //                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
    //                   "username VARCHAR(30) NOT NULL,"
    //                   "email VARCHAR(80),"
    //                   "password VARCHAR(50) NOT NULL"
    //                   ");";

    char *errMsg = nullptr;
    rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::cout << "Erro ao criar a tabela: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        std::cout << "Tabela criada com sucesso." << std::endl;
    }

    sqlite3_close(db);
}

void clearTerminal()
{
    // Se estiver no Windows, substitua `clear` por `cls`
    std::system("clear");
}

void entryError()
{
    std::cerr << "Entrada inválida!" << std::endl;
}

bool mainPage();
bool searchSong();

void runMenu(bool (*function)())
{
    clearTerminal();
    while (!(*function)())
    {
        clearTerminal();
        entryError();
    }
}

bool isValidEntry(std::string entry)
{
    size_t pos;
    try
    {
        int number = std::stoi(entry, &pos);

        if (pos == entry.length())
        {
            std::cout << "Opção selecionada: " << number << std::endl;
            return true;
        }
        else
        {
            std::cout << "A entrada informada contém caracteres inválidos." << std::endl;
            return false;
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "A entrada informada contém caracteres inválidos." << std::endl;
        return false;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "A entrada informada representa um valor fora do intervalo válido para um inteiro." << std::endl;
        return false;
    }
}

int partition(std::vector<Track> &tracks, int low, int high)
{
    std::string pivot = tracks[high].getName();
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (tracks[j].getName() < pivot)
        {
            i++;
            std::swap(tracks[i], tracks[j]);
        }
    }

    std::swap(tracks[i + 1], tracks[high]);
    return i + 1;
}

// Quicksort
void quickSort(std::vector<Track> &tracks, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(tracks, low, high);

        quickSort(tracks, low, pivotIndex - 1);
        quickSort(tracks, pivotIndex + 1, high);
    }
}

std::vector<Track> sortFindedTracks(std::vector<Track> tracks)
{
    quickSort(tracks, 0, tracks.size() - 1);
    return tracks;
}

bool selectSongFromFindedTracks()
{
    int option;
    size_t i;
    std::cout << "_________________________________________________________________________" << std::endl;
    do
    {
        for (i = 0; i < searchedTracksResult->size(); i++)
        {
            std::cout << "|                                         " << std::endl;
            std::cout << "|     " << i << " - " << (*searchedTracksResult)[i].getName() << std::endl;
            std::cout << "|_________________________________________________________________________" << std::endl;
        }
        std::cout << "|                                         " << std::endl;
        std::cout << "|     " << i << " - Sair" << std::endl;
        std::cout << "|_________________________________________________________________________" << std::endl;

        std::cout << "Digite o número da música que deseja ouvir: " << std::endl;
        std::string entry;
        std::cin >> entry;

        if (isValidEntry(entry))
        {
            option = std::stoi(entry, nullptr);
        }
        else
        {
            return false;
        }
        if (option > (int)(i) || option < 0)
        {
            return false;
        }
        if (option == (int)(i))
        {
            runMenu(&mainPage);
            return true;
        }

        Player *player = new Player();

        player->playTrack((*searchedTracksResult)[option].getUrl());

        return true;

    } while ((int)(i) != option);
    return true;
}

bool acessMyPlaylists()
{
    UserDao userDao;

    User *user = new User("Patrick", "patrick@testmail.com", "12345rew");

    //userDao.create(user);

    int option;
    do
    {
        std::cout << " _________________________________________" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|          Bem-vindo, " + user->getUsername() + "             |" << std::endl;
        std::cout << "|_________________________________________|" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|             Suas playlists:             |" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|   1 - Pra relaxar (20 músicas)          |" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|   2 - Estudar LP1 (20 músicas)          |" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|   3 - Treino (20 músicas)               |" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|   4 - Sair                              |" << std::endl;
        std::cout << "|_________________________________________|" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|       Digite uma das opções acima       |" << std::endl;
        std::cout << "|_________________________________________|" << std::endl;

        std::string entry;
        std::cin >> entry;

        if (isValidEntry(entry))
        {
            option = std::stoi(entry, nullptr, 16);
        }
        else
        {
            return false;
        }

        if (option == 1)
        {
            std::vector<Track> findedTracks = sortFindedTracks(spotifyApiService.searchTrackByName("chill relax calm peace rest sleep"));

            if ((int)findedTracks.size() > 0)
            {
                searchedTracksResult = &findedTracks;
                runMenu(selectSongFromFindedTracks);

                return true;
            }
        }
        else if (option == 2)
        {
            std::vector<Track> findedTracks = sortFindedTracks(spotifyApiService.searchTrackByName("meditation study"));

            if ((int)findedTracks.size() > 0)
            {
                searchedTracksResult = &findedTracks;
                runMenu(selectSongFromFindedTracks);

                return true;
            }
        }
        else if (option == 3)
        {
            std::vector<Track> findedTracks = sortFindedTracks(spotifyApiService.searchTrackByName("phonk"));

            if ((int)findedTracks.size() > 0)
            {
                searchedTracksResult = &findedTracks;
                runMenu(selectSongFromFindedTracks);

                return true;
            }
        }
        else if (option == 4)
        {
            runMenu(&mainPage);
            return true;
        }
        else
        {
            return false;
        }
    } while (option != 4);
    return true;
}


bool searchSong()
{
    int option;
    do
    {
        std::cout << " _________________________________________" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|      SpotifySimulator - Pesquisar       |" << std::endl;
        std::cout << "|_________________________________________|" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|   1 - Buscar por título da música       |" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|   2 - Buscar por autor da música        |" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|   3 - Voltar ao menu principal          |" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|   4 - Sair                              |" << std::endl;
        std::cout << "|_________________________________________|" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|       Digite uma das opções acima       |" << std::endl;
        std::cout << "|_________________________________________|" << std::endl;

        std::string entry;
        std::cin >> entry;

        if (isValidEntry(entry))
        {
            option = std::stoi(entry, nullptr, 16);
        }
        else
        {
            return false;
        }

        if (option == 1)
        {
            clearTerminal();
            std::cout << "Informe o título da música: " << std::endl;
            std::string entryMusicName;

            // Pra limpar o buffer de entrada e não bugar o getline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::getline(std::cin, entryMusicName);
            // std::cin >> entryMusicName;

            std::vector<Track> findedTracks = sortFindedTracks(spotifyApiService.searchTrackByName(entryMusicName));

            if ((int)findedTracks.size() > 0)
            {
                searchedTracksResult = &findedTracks;
                runMenu(selectSongFromFindedTracks);

                return true;
            }
            return false;
        }
        else if (option == 2)
        {
            clearTerminal();
            std::cout << "Informe o nome do artista: " << std::endl;
            std::string entryArtistName;

            // Pra limpar o buffer de entrada e não bugar o getline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::getline(std::cin, entryArtistName);
            // std::cin >> entryArtistName;

            std::vector<Track> findedTracks = sortFindedTracks(spotifyApiService.searchTrackByName(entryArtistName));

            if ((int)findedTracks.size() > 0)
            {
                searchedTracksResult = &findedTracks;
                runMenu(selectSongFromFindedTracks);

                return true;
            }
            return false;
        }
        else if (option == 3)
        {
            runMenu(&mainPage);
            return true;
        }
        else if (option == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    } while (option != 4);
    return true;
}

bool mainPage()
{
    int valueEntry;
    do
    {
        std::cout << " _____________________________________________________________________" << std::endl;
        std::cout << "|                                                                     |" << std::endl;
        std::cout << "|                  SpotifySimulator - Página Inicial                  |" << std::endl;
        std::cout << "|_____________________________________________________________________|" << std::endl;
        std::cout << "|                                                                     |" << std::endl;
        std::cout << "|                              Pesquisa:                              |" << std::endl;
        std::cout << "|    1 - Buscar música                                                |" << std::endl;
        std::cout << "|_____________________________________________________________________|" << std::endl;
        std::cout << "|                                                                     |" << std::endl;
        std::cout << "|                               Usuário:                              |" << std::endl;
        std::cout << "|    2 - Acessar minhas playlists                                     |" << std::endl;
        std::cout << "|    3 - Sair                                                         |" << std::endl;
        std::cout << "|_____________________________________________________________________|" << std::endl;
        std::cout << "|                                                                     |" << std::endl;
        std::cout << "|                    Digite uma das opções acima                      |" << std::endl;
        std::cout << "|_____________________________________________________________________|" << std::endl;

        std::string entry;
        std::cin >> entry;

        if (isValidEntry(entry))
        {
            valueEntry = std::stoi(entry, nullptr, 16);
        }
        else
        {
            return false;
        }

        if (valueEntry == 1)
        {
            runMenu(&searchSong);
            return true;
        }
        else if (valueEntry == 2)
        {
            runMenu(&acessMyPlaylists);
            return true;
        }
        else if (valueEntry == 3)
        {
            return true;
        }
        else
        {
            return false;
        }
    } while (valueEntry != 3);
    return true;
}

int main(int argc, char const *argv[])
{

    // auto tracks = spotifyApiService.searchTrackByArtist("Baco Exu do Blues");
    // auto tracks = spotifyApiService.searchTrackByName("Funk");

    // UserDao userDao;

    // User *user = new User("carloss", "c3ps@testmail.com", "12345rew");

    // userDao.create(user);

    // //User *user = userDao.findByUsername("admin");
    // user = userDao.findByEmail("c3ps@testmail.com");

    // if (user != nullptr)
    // {
    //     std::cout << user->getId() << std::endl;
    //     std::cout << user->getUsername() << std::endl;
    //     std::cout << user->getEmail() << std::endl;
    //     std::cout << user->getPassword() << std::endl;
    // }

    // std::string MP3_URL = "https://p.scdn.co/mp3-preview/d72df913287a33253c6415c0c65431b2122f695f?cid=d793a5bbf03749b1a5454ac339001842";

    // Player *player = new Player();

    // player->playTrack(MP3_URL);

    // Track *track = spotifyApiService.getTrack("6bTdZ7xfKp3NqqADJ8HLyj");

    // cout << track->getName() << endl;
    // cout << track->getDuration() << endl;

    // for (auto element : track->getArtists())
    // {
    //     cout << element.getName() << endl;
    // }

    // testConnection();

    runMenu(&mainPage);

    return 0;
}
