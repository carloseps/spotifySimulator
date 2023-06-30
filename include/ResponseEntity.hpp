#if !defined(RESPONSE_ENTITY_HPP)
#define RESPONSE_ENTITY_HPP

#include "HttpStatus.hpp"
#include "ContentType.hpp"

template <typename T>
class ResponseEntity
{
private:
  T body;
  HttpStatus status;
  ContentType contentType;

public:
  ResponseEntity(T, HttpStatus, ContentType);
  ~ResponseEntity();
  T getBody();
  HttpStatus getStatus();
  ContentType getContentType();
};

#endif // RESPONSE_ENTITY_HPP
