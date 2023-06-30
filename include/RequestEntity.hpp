#if !defined(REQUEST_ENTITY_HPP)
#define REQUEST_ENTITY_HPP

#include "HttpMethod.hpp"
#include "Url.hpp"
#include <map>
#include <string>

class RequestEntity
{
private:
  HttpMethod method;
  Url url;
  String body;
  std::map<std::string, std::string> headers;

public:
};

#endif // REQUEST_ENTITY_HPP
