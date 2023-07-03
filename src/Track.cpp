#include <Track.hpp>

Track::Track() {}

Track::Track(int id, std::string name, long duration, std::chrono::system_clock::time_point releaseDate, LinkedList<Artist> artists, std::string url)
    : id(id), name(name), duration(duration), releaseDate(releaseDate), artists(artists), url(url)
{
}

Track::~Track()
{
}

int Track::getId() const
{
    return id;
}

void Track::setId(int id)
{
    this->id = id;
}

std::string Track::getName() const
{
    return name;
}

void Track::setName(const std::string name)
{
    this->name = name;
}

long Track::getDuration() const
{
    return duration;
}

void Track::setDuration(long duration)
{
    this->duration = duration;
}

std::chrono::system_clock::time_point Track::getReleaseDate() const
{
    return releaseDate;
}

void Track::setReleaseDate(const std::chrono::system_clock::time_point releaseDate)
{
    this->releaseDate = releaseDate;
}

LinkedList<Artist> Track::getArtists() const
{
    return artists;
}

void Track::setArtists(const LinkedList<Artist> artists)
{
    this->artists = artists;
}

std::string Track::getUrl() const
{
    return url;
}

void Track::setUrl(const std::string url)
{
    this->url = url;
}
