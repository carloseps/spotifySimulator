#include <Album.h>

Album::Album() {}

Album::Album(int id, std::string name, long duration, LinkedList<Track> tracks, std::string artist, std::chrono::system_clock::time_point releaseDate)
    : TrackList(id, name, duration, tracks), artist(artist), releaseDate(releaseDate)
{
}

Album::~Album()
{
}

std::string Album::getArtist()
{
    return artist;
}

void Album::setArtist(std::string artist)
{
    this->artist = artist;
}

std::chrono::system_clock::time_point Album::getReleaseDate()
{
    return releaseDate;
}

void Album::setReleaseDate(std::chrono::system_clock::time_point releaseDate)
{
    this->releaseDate = releaseDate;
}
