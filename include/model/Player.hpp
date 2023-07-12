#if !defined(PLAYER_HPP)
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <sndfile.h>
#include <vorbis/vorbisenc.h>

class Player
{
private:
    bool downloadTempMP3(std::string);
    void playMP3();
    void convertMP3ToOgg();

public:
    void playTrack(std::string);
};

void Player::playTrack(std::string url)
{
    if (downloadTempMP3(url))
    {
        std::cout << "Track downloaded" << std::endl;
        playMP3();
    }
}

static size_t WriteData(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

bool Player::downloadTempMP3(std::string url)
{
    std::string TMP_FILE_PATH = "./tmp/output.mp3";

    FILE* outputFile = fopen(TMP_FILE_PATH.c_str(), "wb");

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

void Player::playMP3()
{
    convertMP3ToOgg();
    std::string TMP_FILE_PATH = "./tmp/output.ogg";

    SF_INFO fileInfo;
    SNDFILE* file = sf_open(TMP_FILE_PATH.c_str(), SFM_READ, &fileInfo);
    if (!file) {
        std::cout << "Failed to open audio file." << std::endl;
        return;
    }

    // Get audio format information
    int channels = fileInfo.channels;
    int sampleRate = fileInfo.samplerate;

    // Allocate buffer for audio data
    int bufferSize = channels * fileInfo.frames;
    float* buffer = new float[bufferSize];

    // Read audio data
    sf_readf_float(file, buffer, fileInfo.frames);

    // Close the audio file
    sf_close(file);

    // Play audio using paplay
    std::string command = "paplay";
    command += " --rate=" + std::to_string(sampleRate);
    command += " --channels=" + std::to_string(channels);
    command += " /path/to/output.mp3";

    system(command.c_str());

    // Clean up
    delete[] buffer;
}

void Player::convertMP3ToOgg() {
    std::string TMP_FILE_PATH_MP3 = "./tmp/output.mp3";
    std::string TMP_FILE_PATH_OGG = "./tmp/output.ogg";

    FILE* inputFile = fopen(TMP_FILE_PATH_MP3.c_str(), "rb");
    FILE* outputFile = fopen(TMP_FILE_PATH_OGG.c_str(), "wb");

    if (!inputFile || !outputFile) {
        printf("Error opening input or output file.\n");
        return;
    }

    vorbis_info vi;
    vorbis_comment vc;
    vorbis_dsp_state vd;
    vorbis_block vb;
    ogg_stream_state os;

    // Initialize the Vorbis encoder
    vorbis_info_init(&vi);
    vorbis_comment_init(&vc);
    vorbis_encode_init_vbr(&vi, 2, 44100, 0.4);

    // Set up the Ogg bitstream
    ogg_stream_init(&os, rand());

    // Write the Vorbis header
    ogg_packet header;
    ogg_packet header_comm;
    ogg_packet header_code;
    vorbis_analysis_headerout(&vd, &vc, &header, &header_comm, &header_code);
    ogg_stream_packetin(&os, &header);
    ogg_stream_packetin(&os, &header_comm);
    ogg_stream_packetin(&os, &header_code);

    // Write the Ogg pages
    ogg_page og;
    ogg_packet op;

    while (1) {
        int result = ogg_stream_flush(&os, &og);
        if (result == 0) break;
        fwrite(og.header, og.header_len, 1, outputFile);
        fwrite(og.body, og.body_len, 1, outputFile);
    }

    // Clean up
    ogg_stream_clear(&os);
    vorbis_block_clear(&vb);
    vorbis_dsp_clear(&vd);
    vorbis_comment_clear(&vc);
    vorbis_info_clear(&vi);

    fclose(inputFile);
    fclose(outputFile);
}

#endif // PLAYER_HPP
