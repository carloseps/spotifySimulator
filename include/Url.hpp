#if !defined(URL_HPP)
#define URL_HPP

#include <string>
#include <map>

class URL
{
private:
  std::string path;
  std::map<std::string, std::string> params;

public:
  URL();
  URL(std::string);
  URL(std::string, std::map<std::string, std::string>);

  std::string getPath() const;
  void setPath(std::string);

  std::map<std::string, std::string> getParams() const;
  void setParams(const std::map<std::string, std::string> &newParams);

  std::string buildUrlString();
};

#endif // URL_HPP
