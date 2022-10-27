//
// Created by 16117 on 2022/10/21.
//

#include "DatabaseManager.h"

std::shared_ptr<DatabaseManager> DatabaseManager::getInstance() {
    static auto instance = std::shared_ptr<DatabaseManager>(new DatabaseManager());
    return instance;
}

bool DatabaseManager::createDatabase(std::string& databaseName) {
    std::string queryStr = "create database if not exists ";
    queryStr += databaseName;
    if(!mysql_query(&mysql, queryStr.c_str())) {
        queryStr = "use ";
        queryStr += databaseName;
        if(!mysql_query(&mysql, queryStr.c_str())) {}
        return true;
    }

    return false;
}


bool DatabaseManager::connectMySQL() {
    mysql_init(&mysql);
    if(!mysql_real_connect(&mysql, "localhost", "root", "root", "dataTest3", 3306, NULL, 0)){
        printf("Connect Failed\n");
        return false;
    }
    else {
        printf("Connect Success\n");
        return true;
    }

}

void DatabaseManager::closeMySQL() {
    mysql_close(&mysql);
}
