#if !defined(AUTHENTICATION_TOKEN_HPP)
#define AUTHENTICATION_TOKEN_HPP

#include <string>

class AuthenticationToken {
private:
    std::string accessToken;
    std::string tokenType;
    unsigned long expiresIn;
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
};

#endif // AUTHENTICATION_TOKEN_HPP
