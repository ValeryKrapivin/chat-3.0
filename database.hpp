#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <sqlite3.h>
#include <string>

class Database {
public:
    Database(const std::string& db_name);
    ~Database();

    bool register_user(const std::string& username, const std::string& password);
    bool authenticate_user(const std::string& username, const std::string& password);
    void save_message(const std::string& sender, const std::string& receiver, const std::string& message);
    
private:
    sqlite3* db_;
};

#endif // DATABASE_HPP
