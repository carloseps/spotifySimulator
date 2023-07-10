#include <TrackList.h>

TrackList::TrackList() {}

TrackList::TrackList(int id, std::string name, long duration, LinkedList<Track> tracks)
    : id(id), name(name), duration(duration), tracks(tracks) {}

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

long TrackList::getDuration() const
{
    return duration;
}

void TrackList::setDuration(long duration)
{
    this->duration = duration;
}

LinkedList<Track> TrackList::getTracks() const
{
    return tracks;
}

void TrackList::setTracks(const LinkedList<Track> tracks)
{
    this->tracks = tracks;
}
