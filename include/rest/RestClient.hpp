#if !defined(HTTP_CLIENT_HPP)
#define HTTP_CLIENT_HPP

#include <ResponseEntity.hpp>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <map>

class RestClient
{
public:
  RestClient();
  ~RestClient();

  ResponseEntity<nlohmann::json> *get(std::string);
  ResponseEntity<nlohmann::json> *get(std::string, std::map<std::string, std::string>);

  ResponseEntity<nlohmann::json> *post(std::string, std::map<std::string, std::string>);
  ResponseEntity<nlohmann::json> *post(std::string url, std::map<std::string, std::string> body, std::map<std::string, std::string> headers);
};

RestClient::RestClient() {}

RestClient::~RestClient() {}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

ResponseEntity<nlohmann::json> *RestClient::get(std::string url)
{
  ResponseEntity<nlohmann::json> *response = new ResponseEntity<nlohmann::json>();
  CURL *curl;

  std::string contentData;
  long statusCode;

  curl = curl_easy_init();
  if (curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &contentData);
    curl_easy_perform(curl);

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &statusCode);

    curl_easy_cleanup(curl);

    nlohmann::json body = nlohmann::json::parse(contentData);
    HttpStatus httpStatus = static_cast<HttpStatus>(statusCode);

    response->setBody(body);
    response->setStatus(httpStatus);
    response->setContentType(ContentType::APPLICATION_JSON);
  }

  return response;
}

ResponseEntity<nlohmann::json> *RestClient::get(std::string url, std::map<std::string, std::string> headers)
{
  ResponseEntity<nlohmann::json> *response = new ResponseEntity<nlohmann::json>();
  CURL *curl;

  std::string contentData;
  long statusCode;

  curl = curl_easy_init();
  if (curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &contentData);

    struct curl_slist *headerList = nullptr;
    for (const auto &header : headers)
    {
      std::string headerEntry = header.first + ": " + header.second;
      headerList = curl_slist_append(headerList, headerEntry.c_str());
    }

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);

    curl_easy_perform(curl);

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &statusCode);

    curl_easy_cleanup(curl);
    curl_slist_free_all(headerList);

    nlohmann::json body = nlohmann::json::parse(contentData);
    HttpStatus httpStatus = static_cast<HttpStatus>(statusCode);

    response->setBody(body);
    response->setStatus(httpStatus);
    response->setContentType(ContentType::APPLICATION_JSON);
  }

  return response;
}

ResponseEntity<nlohmann::json> *RestClient::post(std::string url, std::map<std::string, std::string> body)
{
  ResponseEntity<nlohmann::json> *response = new ResponseEntity<nlohmann::json>();
  CURL *curl;

  std::string contentData;
  long statusCode;

  curl = curl_easy_init();
  if (curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    std::string encodedData;
    for (const auto &pair : body)
    {
      if (!encodedData.empty())
      {
        encodedData += "&";
      }
      encodedData += pair.first + "=" + pair.second;
    }

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, encodedData.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &contentData);

    curl_easy_perform(curl);

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &statusCode);

    curl_easy_cleanup(curl);

    nlohmann::json body = nlohmann::json::parse(contentData);
    HttpStatus httpStatus = static_cast<HttpStatus>(statusCode);

    response->setBody(body);
    response->setStatus(httpStatus);
    response->setContentType(ContentType::APPLICATION_JSON);
  }

  return response;
}

ResponseEntity<nlohmann::json> *RestClient::post(std::string url, std::map<std::string, std::string> body, std::map<std::string, std::string> headers)
{
  ResponseEntity<nlohmann::json> *response = new ResponseEntity<nlohmann::json>();
  CURL *curl;

  std::string contentData;
  long statusCode;

  curl = curl_easy_init();
  if (curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    std::string encodedData;
    for (const auto &pair : body)
    {
      if (!encodedData.empty())
      {
        encodedData += "&";
      }
      encodedData += pair.first + "=" + pair.second;
    }

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, encodedData.c_str());

    struct curl_slist *headerList = nullptr;
    for (const auto &header : headers)
    {
      std::string headerEntry = header.first + ": " + header.second;
      headerList = curl_slist_append(headerList, headerEntry.c_str());
    }

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &contentData);

    curl_easy_perform(curl);

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &statusCode);

    curl_easy_cleanup(curl);
    curl_slist_free_all(headerList);

    nlohmann::json body = nlohmann::json::parse(contentData);
    HttpStatus httpStatus = static_cast<HttpStatus>(statusCode);

    response->setBody(body);
    response->setStatus(httpStatus);
    response->setContentType(ContentType::APPLICATION_JSON);
  }

  return response;
}

#endif // HTTP_CLIENT_HPP
