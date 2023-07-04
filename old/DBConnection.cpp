#include <iostream>
#include <pqxx/pqxx>
#include <memory>

class DBConnection {
private:
    std::shared_ptr<pqxx::connection> m_connection;

public:
    DBConnection(const std::string& host, const std::string& user, const std::string& password, const std::string& database) {
        connect(host, user, password, database);
    }

    void connect(const std::string& host, const std::string& user, const std::string& password, const std::string& database) {
        std::string connectionString = "host=" + host + " user=" + user + " password=" + password + " dbname=" + database;
        m_connection = std::make_shared<pqxx::connection>(connectionString);
    }

    pqxx::result executeQuery(const std::string& query) {
        pqxx::work txn(*m_connection);
        pqxx::result result = txn.exec(query);
        txn.commit();
        return result;
    }
};
