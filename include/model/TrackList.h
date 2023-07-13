#if !defined(TRACK_LIST_H)
#define TRACK_LIST_H

#include <Track.h>
#include <LinkedList.h>
#include <string>
#include <vector>

class TrackList
{
protected:
  int id;
  std::string name;
  std::vector<Track> tracks;

public:
  TrackList();
  TrackList(int, std::string, std::vector<Track>);

  virtual ~TrackList() = 0;

  int getId() const;
  void setId(int);

  std::string getName() const;
  void setName(const std::string);

  std::vector<Track> getTracks() const;
  void setTracks(const std::vector<Track>);
};

#endif // TRACK_LIST_H
