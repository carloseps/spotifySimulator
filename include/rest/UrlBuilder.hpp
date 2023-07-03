#if !defined(URL_HPP)
#define URL_HPP

#include <string>
#include <map>

// TO DO: Adicionar a opção de interpolar parâmetros do path

class URLBuilder
{
private:
  std::string path;
  std::map<std::string, std::string> *params;

public:
  URLBuilder();
  URLBuilder(std::string);
  URLBuilder(std::string, std::map<std::string, std::string> *);
  ~URLBuilder();

  std::string getPath() const;
  void setPath(std::string);

  std::map<std::string, std::string> getParams() const;
  void setParams(std::map<std::string, std::string> *);

  std::string buildUrlString() const;
};

URLBuilder::URLBuilder() {}

URLBuilder::URLBuilder(std::string path) : path(path), params(nullptr) {}

URLBuilder::URLBuilder(std::string path, std::map<std::string, std::string> *params) : path(path), params(params) {}

URLBuilder::~URLBuilder()
{
  delete[] params;
}

std::string URLBuilder::getPath() const
{
  return this->path;
}

void URLBuilder::setPath(std::string path)
{
  this->path = path;
}

std::map<std::string, std::string> URLBuilder::getParams() const
{
  return *(this->params);
}

void URLBuilder::setParams(std::map<std::string, std::string> *params)
{
  delete this->params;
  this->params = params;
}

std::string URLBuilder::buildUrlString() const
{
  std::string urlString = this->path;

  if (params != nullptr && !(this->params->empty()))
  {
    urlString += "?";
    std::string urlParams;
    for (const auto &pair : *(this->params))
    {
      if (!urlParams.empty())
      {
        urlParams += "&";
      }

      urlParams += pair.first + "=" + pair.second;
    }

    urlString += urlParams;
  }

  return urlString;
}

#endif // URL_HPP
