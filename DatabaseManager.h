//
// Created by 16117 on 2022/10/21.
//

#ifndef DATABASE3_DATABASEMANAGER_H
#define DATABASE3_DATABASEMANAGER_H
#include <iostream>
#include <mysql.h>
#include <memory>

class DatabaseManager {
public:
    static std::shared_ptr<DatabaseManager> getInstance();
    bool createDatabase(std::string& databaseName);
    bool connectMySQL();
    void closeMySQL();
    bool createTable();
    MYSQL mysql;

private:

    MYSQL_RES *res;
    MYSQL_ROW column;
};


#endif //DATABASE3_DATABASEMANAGER_H
