#if !defined(TRACK_H)
#define TRACK_H

#include <Artist.h>
#include <string>
#include <vector>

class Track
{
private:
  int id;
  std::string name;
  long duration;
  std::vector<Artist> artists;
  std::string url;

public:
  Track();

  Track(int, std::string, long, std::vector<Artist>, std::string);

  ~Track();

  int getId() const;
  void setId(int);

  std::string getName() const;
  void setName(const std::string);

  long getDuration() const;
  void setDuration(long);

  std::vector<Artist> getArtists() const;
  void setArtists(const std::vector<Artist>);

  std::string getUrl() const;
  void setUrl(const std::string);
};

#endif // TRACK_H
