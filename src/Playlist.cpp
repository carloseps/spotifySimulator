#include <Playlist.h>

Playlist::Playlist() {}

Playlist::Playlist(int id, std::string name, std::vector<Track> tracks, User owner, PrivacyState privacyState)
    : TrackList(id, name, tracks), owner(owner), privacyState(privacyState) {}

Playlist::~Playlist() {}

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

bool Playlist::addTrack(const Track track)
{
    return false;
}

bool Playlist::removeTrack(const Track track)
{
    return false;
}
