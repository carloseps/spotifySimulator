#include <iostream>
#include <sqlite3/sqlite3.h>
#include <SpotifyApiService.hpp>
#include <Track.hpp>
// #include "DBConnection.cpp"

using namespace std;

void testConnection()
{
    // DBConnection dbConnection(host, user, password, database);

    // try
    // {
    //     dbConnection.executeQuery("SELECT 1");
    //     std::cout << "Conexão com o banco de dados estabelecida com sucesso!" << std::endl;
    //     return true;
    // }
    // catch (const std::exception &e)
    // {
    //     std::cout << "Falha ao conectar ao banco de dados: " << e.what() << std::endl;
    //     return false;
    // }

    sqlite3 *db;
    int rc = sqlite3_open("../database/database.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cout << "Falha ao abrir ao banco de dados" << std::endl;
        sqlite3_close(db);
        return;
    }

    std::cout << "Banco de dados aberto com sucesso!" << std::endl;

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

int main(int argc, char const *argv[])
{
    SpotifyApiService spotifyApiService;

    Track *track = spotifyApiService.getTrack("5oI9blwsXC8AkTWw6wASY8");

    cout << track->getName() << endl;
    cout << track->getDuration() << endl;

    // Conexão com o banco e chamada do menu inicial

    // std::string host = "192.168.1.68";
    // std::string user = "postgres";
    // std::string password = "000123";
    // std::string database = "SpotifySimulator";

    testConnection();

    // runMenu(&mainPage);

    return 0;
}
