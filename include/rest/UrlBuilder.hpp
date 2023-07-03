#if !defined(URL_HPP)
#define URL_HPP

#include <string>
#include <map>

class URL
{
private:
  std::string path;
  std::map<std::string, std::string> *params;

public:
  URL();
  URL(std::string);
  URL(std::string, std::map<std::string, std::string> *);
  ~URL();

  std::string getPath() const;
  void setPath(std::string);

  std::map<std::string, std::string> getParams() const;
  void setParams(std::map<std::string, std::string> *);

  std::string buildUrlString() const;
};

URL::URL() {}

URL::URL(std::string path) : path(path), params(nullptr) {}

URL::URL(std::string path, std::map<std::string, std::string> *params) : path(path), params(params) {}

URL::~URL()
{
  delete[] params;
}

std::string URL::getPath() const
{
  return this->path;
}

void URL::setPath(std::string path)
{
  this->path = path;
}

std::map<std::string, std::string> URL::getParams() const
{
  return *(this->params);
}

void URL::setParams(std::map<std::string, std::string> *params)
{
  delete this->params;
  this->params = params;
}

std::string URL::buildUrlString() const
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
