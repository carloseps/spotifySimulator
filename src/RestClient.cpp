#include <RestClient.hpp>
#include <string>
#include <map>

RestClient::RestClient(){};

RestClient::~RestClient(){};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

ResponseEntity<nlohmann::json> *get(std::string url)
{
  ResponseEntity<nlohmann::json> *response = new ResponseEntity<nlohmann::json>();
  CURL *curl;
  CURLcode res;

  std::string contentData;
  long statusCode;
  char *contentType;

  curl = curl_easy_init();
  if (curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &contentData);
    res = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &statusCode);
    curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &contentType);
    curl_easy_cleanup(curl);

    nlohmann::json body = nlohmann::json::parse(contentData);
    HttpStatus httpStatus = static_cast<HttpStatus>(statusCode);

    response->setBody(body);
    response->setStatus(httpStatus);
  }

  return response;
}