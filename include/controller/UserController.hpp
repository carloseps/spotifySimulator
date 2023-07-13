#if !defined(USER_CONTROLLER_HPP)
#define USER_CONTROLLER_HPP

#include <User.h>
#include <UserDao.hpp>
#include <string>

class UserController
{
private:
  UserDao userDao;

public:
  UserController();
  ~UserController();
  User *login(std::string, std::string);
  bool registrar(std::string, std::string, std::string);
};

UserController::UserController() {}

UserController::~UserController() {}

User *UserController::login(std::string email, std::string password)
{
  User *user = this->userDao.findByEmail(email);

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

bool UserController::registrar(std::string username, std::string email, std::string password)
{
  User *user = new User(username, email, password);

  if (userDao.create(user))
  {
    std::cout << "Usuario criado com sucesso" << std::endl;
    return true;
  }

  return false;
}

#endif // USER_CONTROLLER_HPP
