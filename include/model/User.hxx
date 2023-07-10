#if !defined(USER_HXX)
#define USER_HXX

#include <string>
#include <odb/core.hxx>

#pragma db object
class User
{
protected:
#pragma db id auto
  unsigned long id;

  std::string username;
  std::string email;
  std::string password;
  friend class odb::access;

public:
  User();
  User(int, const std::string, const std::string, const std::string);

  ~User();

  int getId() const;
  void setId(int);

  const std::string getUsername() const;
  void setUsername(const std::string);

  const std::string getEmail() const;
  void setEmail(const std::string);

  const std::string getPassword() const;
  void setPassword(const std::string);
};

#endif // USER_HXX
