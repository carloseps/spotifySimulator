#include <Track.h>
#include <vector>

Track::Track() {}

Track::Track(int id, std::string name, long duration, std::vector<Artist> artists, std::string url)
    : id(id), name(name), duration(duration), artists(artists), url(url)
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

std::vector<Artist> Track::getArtists() const
{
    return artists;
}

void Track::setArtists(const std::vector<Artist> artists)
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
