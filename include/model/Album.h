#if !defined(ALBUM_H)
#define ALBUM_H

#include <TrackList.h>
#include <LinkedList.h>
#include <Track.h>
#include <chrono>

class Album : public TrackList
{
private:
  std::string artist;
  std::chrono::system_clock::time_point releaseDate;

public:
  Album();
  Album(int, std::string, long, LinkedList<Track>, std::string, std::chrono::system_clock::time_point);

  ~Album();

  std::string getArtist();
  void setArtist(std::string);

  std::chrono::system_clock::time_point getReleaseDate();
  void setReleaseDate(std::chrono::system_clock::time_point);
};

#endif // ALBUM_H
