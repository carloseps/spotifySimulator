#if !defined(USER_H)
#define USER_H

#include <string>

class User
{
protected:
  int id;
  std::string username;
  std::string email;
  std::string password;

public:
  User();
  User(const std::string, const std::string, const std::string);
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

#endif // USER_H
