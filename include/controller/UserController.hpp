#if !defined(USER_CONTROLLER_HPP)
#define USER_CONTROLLER_HPP

#include <User.h>
#include <string>

class UserController
{
private:
  UserDao userDao;

public:
  UserController();
  ~UserController();
  User *login(std::string, std::string);
};

UserController::UserController() {}

UserController::~UserController() {}

User *login(std::string email, std::string password)
{
  User *user = userDao.findByEmail(email);

  if (user == nullptr)
  {
    std::cout << "Usuario nao encontrado" << std::endl;
    return nullptr;
  }

  if (user->getPassword() != password)
  {
    std::cout << "Senha incorreta" << std::endl;
    return nullptr;
  }

  return user;
}

#endif // USER_CONTROLLER_HPP
