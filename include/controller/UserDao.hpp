#if !defined(USER_DAO_HPP)
#define USER_DAO_HPP

#include <User.h>
#include <sqlite3/sqlite3.h>
#include <iostream>

class UserDao
{
private:
  sqlite3 *db;

public:
  UserDao();
  ~UserDao();
  User *findByUsername(std::string);
  User *findByEmail(std::string);
  bool create(User *);
};

UserDao::UserDao() {}

UserDao::~UserDao() {}

User *UserDao::findByUsername(std::string username)
{
  User *user = new User();

  int rc = sqlite3_open("./database/database.db", &db);

  if (rc != SQLITE_OK)
  {
    std::cout << "Failed to open database" << std::endl;
    return nullptr;
  }

  std::string query = "SELECT * FROM users WHERE username = '" + username + "';";

  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);

  if (rc != SQLITE_OK)
  {
    std::cout << "Failed to execute query" << std::endl;
    return nullptr;
  }

  rc = sqlite3_step(stmt);

  if (rc == SQLITE_ROW)
  {
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char *username = sqlite3_column_text(stmt, 1);
    const unsigned char *email = sqlite3_column_text(stmt, 2);
    const unsigned char *password = sqlite3_column_text(stmt, 3);

    user->setId(id);
    user->setUsername(reinterpret_cast<const char *>(username));
    user->setEmail(reinterpret_cast<const char *>(email));
    user->setPassword(reinterpret_cast<const char *>(password));
  }
  else
  {
    return nullptr;
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return user;
}

User *UserDao::findByEmail(std::string email)
{
  User *user = new User();

  int rc = sqlite3_open("./database/database.db", &db);

  if (rc != SQLITE_OK)
  {
    std::cout << "Failed to open database" << std::endl;
    return nullptr;
  }

  std::string query = "SELECT * FROM users WHERE email = '" + email + "';";

  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);

  if (rc != SQLITE_OK)
  {
    std::cout << "Failed to execute query" << std::endl;
    return nullptr;
  }

  rc = sqlite3_step(stmt);

  if (rc == SQLITE_ROW)
  {
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char *username = sqlite3_column_text(stmt, 1);
    const unsigned char *email = sqlite3_column_text(stmt, 2);
    const unsigned char *password = sqlite3_column_text(stmt, 3);

    user->setId(id);
    user->setUsername(reinterpret_cast<const char *>(username));
    user->setEmail(reinterpret_cast<const char *>(email));
    user->setPassword(reinterpret_cast<const char *>(password));
  }
  else
  {
    return nullptr;
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return user;
}

bool UserDao::create(User *user)
{
  if (user == nullptr)
  {
    return false;
  }

  int rc = sqlite3_open("./database/database.db", &db);

  if (rc != SQLITE_OK)
  {
    std::cout << "Failed to open database" << std::endl;
    return false;
  }

  std::string query = "INSERT INTO users (username, email, password) VALUES ('" +
                      user->getUsername() + "', '" + user->getEmail() + "', '" + user->getPassword() + "');";

  rc = sqlite3_exec(db, query.c_str(), 0, 0, NULL);

  sqlite3_close(db);

  if (rc != SQLITE_OK)
  {
    std::cout << "Failed to open database" << std::endl;
    return false;
  }

  return true;
}

#endif // USER_DAO_HPP
