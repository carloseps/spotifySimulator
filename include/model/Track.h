#if !defined(TRACK_H)
#define TRACK_H

#include <LinkedList.h>
#include <Artist.h>
#include <string>
#include <chrono>
#include <odb/core.hxx>

class Track
{
private:
  int id;
  std::string name;
  long duration;
  std::chrono::system_clock::time_point releaseDate;
  LinkedList<Artist> artists;
  std::string url;
  friend class odb::access;

public:
  Track();

  Track(int, std::string, long, std::chrono::system_clock::time_point, LinkedList<Artist>, std::string);

  ~Track();

  int getId() const;
  void setId(int);

  std::string getName() const;
  void setName(const std::string);

  long getDuration() const;
  void setDuration(long);

  std::chrono::system_clock::time_point getReleaseDate() const;
  void setReleaseDate(const std::chrono::system_clock::time_point);

  LinkedList<Artist> getArtists() const;
  void setArtists(const LinkedList<Artist>);

  std::string getUrl() const;
  void setUrl(const std::string);
};

#endif // TRACK_H
