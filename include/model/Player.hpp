#if !defined(PLAYER_HPP)
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <sndfile.h>

static const std::string OUTPUT_PATH = "./tmp/output.mp3";

static const std::string SONG_PATH = "./tmp/song.wav";

class Player
{
private:
    bool downloadTempMP3(std::string);
    bool convertMP3toWAV(const std::string& inputFilename, const std::string& outputFilename) {
        SF_INFO inputInfo{};
        SF_INFO outputInfo{};
        inputInfo.format = 0;

        SNDFILE* inputFile = sf_open(inputFilename.c_str(), SFM_READ, &inputInfo);
        if (!inputFile) {
            std::cerr << "Erro ao abrir o arquivo de entrada" << std::endl;
            return false;
        }

        outputInfo = inputInfo;
        outputInfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

        SNDFILE* outputFile = sf_open(outputFilename.c_str(), SFM_WRITE, &outputInfo);
        if (!outputFile) {
            std::cerr << "Erro ao criar o arquivo de saída" << std::endl;
            sf_close(inputFile);
            return false;
        }

        constexpr int bufferSize = 1024;
        std::vector<short> buffer(bufferSize * inputInfo.channels);

        sf_count_t framesRead;
        while ((framesRead = sf_readf_short(inputFile, buffer.data(), bufferSize)) > 0) {
            sf_writef_short(outputFile, buffer.data(), framesRead);
        }

        sf_close(inputFile);
        sf_close(outputFile);

        std::cout << "Conversão deu certo! " << inputFilename << " -> " << outputFilename << std::endl;

        return true;
    }

    void playSong() {

        convertMP3toWAV(OUTPUT_PATH, SONG_PATH);

        std::string command = "pulseaudio --start" ;

        // Executar o comando usando system()
        int result = std::system(command.c_str());

        command = "paplay " + SONG_PATH;

        // Executar o comando usando system()
        result = std::system(command.c_str());

        // Verificar se a execução foi bem-sucedida
        if (result == -1) {
            std::cerr << "Erro ao reproduzir o áudio" << std::endl;
        }
    }

public:
    void playTrack(std::string);
};

void Player::playTrack(std::string url)
{
    if (downloadTempMP3(url))
    {
        playSong();
        std::cout << "Track downloaded" << std::endl;
    }
}

static size_t WriteData(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

bool Player::downloadTempMP3(std::string url)
{
    FILE* outputFile = fopen(OUTPUT_PATH.c_str(), "wb");

    if (!outputFile) {
        std::cout << "Failed to open output file." << std::endl;
        return false;
    }

    CURL* curl = curl_easy_init();
    if (!curl) {
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

    if (res != CURLE_OK) {
        std::cout << "Failed to download MP3 file: " << curl_easy_strerror(res) << std::endl;
        return false;
    }

    return true;
}

#endif // PLAYER_HPP
