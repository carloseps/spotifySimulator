#include <iostream>
#include <sqlite3/sqlite3.h>
#include <SpotifyApiService.hpp>
#include <Track.h>
#include <sndfile.h>
#include <curl/curl.h>

using namespace std;

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
    std::cerr << "Digite uma opção válida! Use somente números" << std::endl;
}

bool mainPage();
bool searchSong();
bool searchPlaylist();

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

bool acessMyPlaylists(/*User user*/)
{
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
            // searchSongByTitle
            return true;
        }
        else if (option == 2)
        {
            // searchSongByAuthor
            return true;
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

bool searchPlaylist()
{
    int option;
    do
    {
        std::cout << " _________________________________________" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|      SpotifySimulator - Pesquisar       |" << std::endl;
        std::cout << "|_________________________________________|" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|   1 - Buscar por nome da playlist       |" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|   2 - Voltar ao menu principal          |" << std::endl;
        std::cout << "|                                         |" << std::endl;
        std::cout << "|   3 - Sair                              |" << std::endl;
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
            // searchSongByTitle
            return true;
        }
        else if (option == 2)
        {
            runMenu(&mainPage);
            return true;
        }
        else if (option == 3)
        {
            return true;
        }
        else
        {
            return false;
        }
    } while (option != 3);
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
        std::cout << "|    2 - Buscar playlist                                              |" << std::endl;
        std::cout << "|_____________________________________________________________________|" << std::endl;
        std::cout << "|                                                                     |" << std::endl;
        std::cout << "|                               Usuário:                              |" << std::endl;
        std::cout << "|    3 - Acessar minhas playlists                                     |" << std::endl;
        std::cout << "|    4 - Sair                                                         |" << std::endl;
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
            runMenu(&searchPlaylist);
            return true;
        }
        else if (valueEntry == 3)
        {
            std::cout << "MENU 3: " << std::endl;
            return true;
        }
        else if (valueEntry == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    } while (valueEntry != 4);
    return true;
}

static size_t WriteData(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int main(int argc, char const *argv[])
{
    SpotifyApiService spotifyApiService;

    auto tracks = spotifyApiService.searchTrackByArtist("Baco Exu do Blues");

    for (auto track : tracks)
    {
        cout << track.getName() << endl;
        cout << track.getUrl() << endl;
    }

    std::string MP3_URL = "https://p.scdn.co/mp3-preview/d72df913287a33253c6415c0c65431b2122f695f?cid=d793a5bbf03749b1a5454ac339001842";

    std::string TMP_FILE_PATH = "./tmp/output.mp3";

    FILE* outputFile = fopen(TMP_FILE_PATH.c_str(), "wb");

    if (!outputFile) {
        std::cout << "Failed to open output file." << std::endl;
    }

    std::cout << "File opened" << std::endl;

    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cout << "Failed to initialize curl." << std::endl;
        fclose(outputFile);
    }

    std::cout << "Curl initialized" << std::endl;

    curl_easy_setopt(curl, CURLOPT_URL, MP3_URL.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, outputFile);

    CURLcode res = curl_easy_perform(curl);
    fclose(outputFile);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        std::cout << "Failed to download MP3 file: " << curl_easy_strerror(res) << std::endl;
    }

    // Track *track = spotifyApiService.getTrack("6bTdZ7xfKp3NqqADJ8HLyj");

    // cout << track->getName() << endl;
    // cout << track->getDuration() << endl;

    // for (auto element : track->getArtists())
    // {
    //     cout << element.getName() << endl;
    // }

    // testConnection();

    // runMenu(&mainPage);

    return 0;
}
