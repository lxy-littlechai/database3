//
// Created by 16117 on 2022/10/21.
//

#include "DatabaseManager.h"
#include <iomanip>

char query[150];
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

void DatabaseManager::showTable() {
//    column = mysql_num_fields(result);
//    int length = 12;
//    int tableRowLength = 0;
//
//    std::vector<char*> empty;
//    table.clear();
//    table.push_back(empty);
//
//    while((field = mysql_fetch_field(result))) {
//        table[tableRowLength].push_back(field->name);
//        std::cout << std::setw(length) << field->name;
//    }
//    std::cout << std::endl;
//
//    while((row = mysql_fetch_row(result))) {
//        for(int i = 0;i < column;i ++) {
//            table.push_back(empty);
//            tableRowLength ++;
//            if(row[i] == NULL) {
//                table[table.size()].push_back(const_cast<char*>("NULL"));
//                std::cout << std::setw(length) << "NULL";
//            } else {
//                table[table.size()].push_back(row[i]);
//                std::cout << std::setw(length) << row[i];
//            }
//
//        }
//        std::cout << std::endl;
//    }
//    mysql_free_result(result);
//    return table;
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
