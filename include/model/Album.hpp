#if !defined(ALBUM_HPP)
#define ALBUM_HPP

#include <TrackList.hpp>
#include <Artist.hpp>
#include <LinkedList.hpp>
#include <Track.hpp>
#include <chrono>

class Album : public TrackList
{
private:
  Artist artist;
  std::chrono::system_clock::time_point releaseDate;

public:
  Album();
  Album(int, std::string, long, LinkedList<Track>, Artist, std::chrono::system_clock::time_point);

  ~Album();

  Artist getArtist();
  void setArtist(Artist);

  std::chrono::system_clock::time_point getReleaseDate();
  void setReleaseDate(std::chrono::system_clock::time_point);
};

#endif // ALBUM_HPP
