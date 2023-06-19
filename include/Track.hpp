#if !defined(TRACK_HPP)
#define TRACK_HPP

#include "../include/LinkedList.hpp"
#include "../include/Artist.hpp"
#include <string>
#include <chrono>

class Track
{
private:
  int id;
  std::string name;
  long duration;
  std::chrono::system_clock::time_point releaseDate;
  LinkedList<Artist> artists;
  std::string url;

public:
  Track(){};
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

#endif // TRACK_HPP
