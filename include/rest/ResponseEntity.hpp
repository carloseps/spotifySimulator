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
  ResponseEntity();
  ResponseEntity(T, HttpStatus, ContentType);
  ~ResponseEntity();

  T getBody() const;
  void setBody(T);

  HttpStatus getStatus() const;
  void setStatus(HttpStatus);

  ContentType getContentType() const;
  void setContentType(ContentType);
};

template <typename T>
ResponseEntity<T>::ResponseEntity() {}

template <typename T>
ResponseEntity<T>::ResponseEntity(T body, HttpStatus status, ContentType contentType) : body(body), status(status), contentType(contentType) {}

template <typename T>
T ResponseEntity<T>::getBody() const
{
  return this->body;
}

template <typename T>
void ResponseEntity<T>::setBody(T body)
{
  this->body = body;
}

template <typename T>
HttpStatus ResponseEntity<T>::getStatus() const
{
  return this->status;
}

template <typename T>
void ResponseEntity<T>::setStatus(HttpStatus status)
{
  this->status = status;
}

template <typename T>
ContentType ResponseEntity<T>::getContentType() const
{
  return this->contentType;
}

template <typename T>
void ResponseEntity<T>::setContentType(ContentType contentType)
{
  this->contentType = contentType;
}

#endif // RESPONSE_ENTITY_HPP
