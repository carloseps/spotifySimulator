#include <TrackList.h>

TrackList::TrackList() {}

TrackList::TrackList(int id, std::string name, std::vector<Track> tracks)
    : id(id), name(name), tracks(tracks) {}

TrackList::~TrackList() {}

int TrackList::getId() const
{
    return id;
}

void TrackList::setId(int id)
{
    this->id = id;
}

std::string TrackList::getName() const
{
    return name;
}

void TrackList::setName(const std::string name)
{
    this->name = name;
}

std::vector<Track> TrackList::getTracks() const
{
    return tracks;
}

void TrackList::setTracks(const std::vector<Track> tracks)
{
    this->tracks = tracks;
}
