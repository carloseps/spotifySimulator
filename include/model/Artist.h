#if !defined(ARTIST_H)
#define ARTIST_H

#include <string>

class Artist
{
private:
  std::string name;

public:
  Artist();
  Artist(const std::string);

  ~Artist();

  const std::string getName() const;
  void setName(const std::string);
};

#endif // ARTIST_H
