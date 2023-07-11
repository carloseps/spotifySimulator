#include <Artist.h>

Artist::Artist() {}

Artist::Artist(const std::string name) : name(name) {}

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
