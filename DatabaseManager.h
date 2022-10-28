//
// Created by 16117 on 2022/10/21.
//

#ifndef DATABASE3_DATABASEMANAGER_H
#define DATABASE3_DATABASEMANAGER_H
#include <iostream>
#include <vector>
#include <mysql.h>
#include <memory>

class DatabaseManager {
public:
    static std::shared_ptr<DatabaseManager> getInstance();
    bool createDatabase(std::string& databaseName);
    bool connectMySQL();
    void closeMySQL();
    bool createTable();
    std::vector<std::vector<char*>> showTable(bool header=true);
    MYSQL mysql;

    MYSQL_RES *result;
    MYSQL_FIELD *field;
    MYSQL_ROW row;
    int column;
    std::vector<std::vector<char*>> table;

private:
    DatabaseManager() = default;
};


#endif //DATABASE3_DATABASEMANAGER_H
