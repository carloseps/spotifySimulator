#if !defined(COLUMN_HPP)
#define COLUMN_HPP

#include <string>

class Column
{
public:
  explicit Column(const std::string &name) : columnName(name) {}

  const std::string &getName() const
  {
    return columnName;
  }

private:
  std::string columnName;
};

#endif // COLUMN_HPP
