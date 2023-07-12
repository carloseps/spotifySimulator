#if !defined(TRACK_H)
#define TRACK_H

#include <string>
#include <vector>

class Track
{
private:
  int id;
  std::string name;
  long duration;
  std::vector<std::string> artists;
  std::string url;

public:
  Track();

  Track(int, std::string, long, std::vector<std::string>, std::string);

  ~Track();

  int getId() const;
  void setId(int);

  std::string getName() const;
  void setName(const std::string);

  long getDuration() const;
  void setDuration(long);

  std::vector<std::string> getArtists() const;
  void setArtists(const std::vector<std::string>);

  std::string getUrl() const;
  void setUrl(const std::string);
};

#endif // TRACK_H
