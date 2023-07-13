#if !defined(PLAYLIST_H)
#define PLAYLIST_H

#include <TrackList.h>
#include <User.h>
#include <PrivacyState.h>
#include <LinkedList.h>
#include <Track.h>
#include <string>
#include <chrono>
#include <vector>

class Playlist : public TrackList
{
private:
  User owner;
  PrivacyState privacyState;

public:
  Playlist();
  Playlist(int, std::string, std::vector<Track>, User, PrivacyState);

  ~Playlist();

  User getOwner() const;
  void setOwner(const User);

  PrivacyState getPrivacyState() const;
  void setPrivacyState(PrivacyState);

  bool addTrack(const Track);
  bool removeTrack(const Track);
};

#endif // PLAYLIST_H
