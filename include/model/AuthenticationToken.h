#if !defined(AUTHENTICATION_TOKEN_H)
#define AUTHENTICATION_TOKEN_H

#include <string>
#include <chrono>

class AuthenticationToken
{
private:
    std::string accessToken;
    std::string tokenType;
    unsigned long expiresIn;
    std::chrono::system_clock::time_point createdAt;

public:
    AuthenticationToken();
    AuthenticationToken(std::string, std::string, unsigned long);
    ~AuthenticationToken();

    std::string getAccessToken();
    void setAccessToken(std::string);

    std::string getTokenType();
    void setTokenType(std::string);

    unsigned long getExpiresIn();
    void setExpiresIn(unsigned long);

    bool isExpired();
};

AuthenticationToken::AuthenticationToken() {}

AuthenticationToken::AuthenticationToken(std::string accessToken, std::string tokenType, unsigned long expiresIn) : accessToken(accessToken), tokenType(tokenType), expiresIn(expiresIn), createdAt(std::chrono::system_clock::now()) {}

AuthenticationToken::~AuthenticationToken() {}

std::string AuthenticationToken::getAccessToken()
{
    return this->accessToken;
}

void AuthenticationToken::setAccessToken(std::string accessToken)
{
    this->accessToken = accessToken;
}

std::string AuthenticationToken::getTokenType()
{
    return this->tokenType;
}

void AuthenticationToken::setTokenType(std::string tokenType)
{
    this->tokenType = tokenType;
}

unsigned long AuthenticationToken::getExpiresIn()
{
    return this->expiresIn;
}

void AuthenticationToken::setExpiresIn(unsigned long expiresIn)
{
    this->expiresIn = expiresIn;
}

bool AuthenticationToken::isExpired()
{
    return this->createdAt + std::chrono::seconds(this->expiresIn) < std::chrono::system_clock::now();
}

#endif // AUTHENTICATION_TOKEN_H
