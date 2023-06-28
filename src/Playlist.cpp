#include "../include/Playlist.hpp"

Playlist::Playlist(int id, std::string name, long duration, LinkedList<Track> tracks, User owner, PrivacyState privacyState, std::chrono::system_clock::time_point createdAt)
    : TrackList(id, name, duration, tracks), owner(owner), privacyState(privacyState), createdAt(createdAt)
{
}

Playlist::~Playlist()
{
}

User Playlist::getOwner() const
{
    return owner;
}

void Playlist::setOwner(const User owner)
{
    this->owner = owner;
}

PrivacyState Playlist::getPrivacyState() const
{
    return privacyState;
}

void Playlist::setPrivacyState(PrivacyState privacyState)
{
    this->privacyState = privacyState;
}

std::chrono::system_clock::time_point Playlist::getCreatedAt() const
{
    return createdAt;
}

void Playlist::setCreatedAt(const std::chrono::system_clock::time_point createdAt)
{
    this->createdAt = createdAt;
}

bool Playlist::addTrack(const Track track)
{
    return TrackList::addTrack(track);
}

bool Playlist::removeTrack(const Track track)
{
    return TrackList::removeTrack(track);
}
