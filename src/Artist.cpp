#include <Artist.hpp>

Artist::Artist() {}

Artist::Artist(int id, const std::string username, const std::string password, const std::string email,
               const std::string name, bool verified)
    : User(id, username, password, email), name(name), verified(verified) {}

Artist::~Artist()
{
}

const std::string Artist::getName() const
{
    return name;
}

void Artist::setName(const std::string name)
{
    this->name = name;
}

bool Artist::isVerified() const
{
    return verified;
}

void Artist::setVerified(bool verified)
{
    this->verified = verified;
}
