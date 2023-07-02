#if !defined(HTTP_STATUS_HPP)
#define HTTP_STATUS_HPP

enum class HttpStatus
{
  // Informational
  CONTINUE = 100,
  SWITCHING_PROTOCOLS = 101,
  PROCESSING = 102,

  // Success
  OK = 200,
  CREATED = 201,
  ACCEPTED = 202,

  // Redirection
  MULTIPLE_CHOICES = 300,
  MOVED_PERMANENTLY = 301,
  FOUND = 302,

  // Client Error
  BAD_REQUEST = 400,
  UNAUTHORIZED = 401,
  FORBIDDEN = 403,

  // Server Error
  INTERNAL_SERVER_ERROR = 500,
  NOT_IMPLEMENTED = 501,
  BAD_GATEWAY = 502
};

#endif // HTTP_STATUS_HPP
