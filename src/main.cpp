#include <iostream>
#include <SpotifyApiService.hpp>
#include <Track.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
    SpotifyApiService spotifyApiService;

    Track *track = spotifyApiService.getTrack("5oI9blwsXC8AkTWw6wASY8");

    cout << track->getName() << endl;
    cout << track->getDuration() << endl;
    return 0;
}
