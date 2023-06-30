#if !defined(PLAYLIST_HPP)
#define PLAYLIST_HPP

#include "../include/TrackList.hpp"
#include "../include/User.hpp"
#include "../include/PrivacyState.hpp"
#include "../include/LinkedList.hpp"
#include "../include/Track.hpp"
#include <string>
#include <chrono>

class Playlist : public TrackList
{
private:
  User owner;
  PrivacyState privacyState;
  std::chrono::system_clock::time_point createdAt;

public:
  Playlist(){};
  Playlist(int, std::string, long, LinkedList<Track>, User, PrivacyState, std::chrono::system_clock::time_point);

  ~Playlist();

  User getOwner() const;
  void setOwner(const User);

  PrivacyState getPrivacyState() const;
  void setPrivacyState(PrivacyState);

  std::chrono::system_clock::time_point getCreatedAt() const;
  void setCreatedAt(const std::chrono::system_clock::time_point);

  bool addTrack(const Track);
  bool removeTrack(const Track);
};

#endif // PLAYLIST_HPP