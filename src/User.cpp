#include <User.hpp>

User::User() {}

User::User(int id, const std::string username, const std::string email, const std::string password)
    : id(id), username(username), email(email), password(password) {}

User::~User() {}

int User::getId() const
{
    return id;
}

void User::setId(int id)
{
    this->id = id;
}

const std::string User::getUsername() const
{
    return username;
}

void User::setUsername(const std::string username)
{
    this->username = username;
}

const std::string User::getEmail() const
{
    return email;
}

void User::setEmail(const std::string email)
{
    this->email = email;
}

const std::string User::getPassword() const
{
    return password;
}

void User::setPassword(const std::string password)
{
    this->password = password;
}
