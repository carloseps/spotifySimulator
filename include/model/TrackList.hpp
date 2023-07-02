#if !defined(TRACK_LIST_HPP)
#define TRACK_LIST_HPP

#include "../include/Track.hpp"
#include "../include/LinkedList.hpp"
#include <string>

class TrackList
{
protected:
  int id;
  std::string name;
  long duration;
  LinkedList<Track> tracks;

public:
  TrackList(){};
  TrackList(int, std::string, long, LinkedList<Track>);

  virtual ~TrackList() = 0;

  int getId() const;
  void setId(int);

  std::string getName() const;
  void setName(const std::string);

  long getDuration() const;
  void setDuration(long);

  LinkedList<Track> getTracks() const;
  void setTracks(const LinkedList<Track>);
};

#endif // TRACK_LIST_HPP
