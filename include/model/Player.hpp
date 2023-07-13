#if !defined(PLAYER_HPP)
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <curl/curl.h>

class Player
{
private:
    bool downloadTempMP3(std::string);
    void playMP3();
    bool convertMP3ToOgg();

public:
    void playTrack(std::string);
};

void Player::playTrack(std::string url)
{
    if (downloadTempMP3(url))
    {
        std::cout << "Reproduzindo Musica [Pressione Ctrl + C para parar]" << std::endl;
        playMP3();
    }
}

static size_t WriteData(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    return fwrite(ptr, size, nmemb, stream);
}

bool Player::downloadTempMP3(std::string url)
{
    std::string TMP_FILE_PATH = "./tmp/output.mp3";

    FILE *outputFile = fopen(TMP_FILE_PATH.c_str(), "wb");

    if (!outputFile)
    {
        std::cout << "Failed to open output file." << std::endl;
        return false;
    }

    CURL *curl = curl_easy_init();
    if (!curl)
    {
        std::cout << "Failed to initialize curl." << std::endl;
        fclose(outputFile);
        return false;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, outputFile);

    CURLcode res = curl_easy_perform(curl);
    fclose(outputFile);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK)
    {
        std::cout << "Failed to download MP3 file: " << curl_easy_strerror(res) << std::endl;
        return false;
    }

    return true;
}

void Player::playMP3()
{
    if (convertMP3ToOgg())
    {
        std::string TMP_OGG_FILE_PATH = "./tmp/output.ogg";

        std::string command = "pulseaudio --start";
        system(command.c_str());

        command = "paplay ";
        command += TMP_OGG_FILE_PATH;

        system(command.c_str());
    }
}

bool Player::convertMP3ToOgg()
{
    std::string TMP_INPUT_FILE_PATH = "./tmp/output.mp3";
    std::string TMP_OUTPUT_FILE_PATH = "./tmp/output.ogg";
    const std::string command = "ffmpeg -hide_banner -loglevel error -y -i " + TMP_INPUT_FILE_PATH + " -c:a libvorbis " + TMP_OUTPUT_FILE_PATH;

    int result = system(command.c_str());

    if (result == 0)
    {
        return true;
    }

    return false;
}

#endif // PLAYER_HPP
