#if !defined(ARTIST_H)
#define ARTIST_H

#include <string>
#include <User.hxx>

class Artist : public User
{
private:
  std::string name;
  bool verified;

public:
  Artist();
  Artist(int, const std::string, const std::string, const std::string,
         const std::string, bool);

  ~Artist();

  const std::string getName() const;
  void setName(const std::string);

  bool isVerified() const;
  void setVerified(bool);
};

#endif // ARTIST_H
