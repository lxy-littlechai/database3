//
// Created by 16117 on 2022/10/21.
//

#include "DatabaseManager.h"
#include <iomanip>

char query[1500];
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

std::vector<std::vector<char*>> DatabaseManager::showTable(bool header) {
    column = mysql_num_fields(result);
    int length = 12;
    int tableRowLength = 0;

    static std::vector<char*> empty;
    for(int i = 0;i < table.size();i ++) {
        table[i].clear();
    }
    table.clear();
    table.push_back(empty);

    if(header) {
        while((field = mysql_fetch_field(result))) {
            table[tableRowLength].push_back(field->name);
            std::cout << std::setw(length) << field->name;
        }
        std::cout << std::endl;
    }


    while((row = mysql_fetch_row(result))) {
        tableRowLength ++;
        table.push_back(empty);
        for(int i = 0;i < column;i ++) {

            if(row[i] == NULL) {
                table[tableRowLength].push_back(const_cast<char*>("NULL"));
                std::cout << std::setw(length) << "NULL";
            } else {
                table[tableRowLength].push_back(row[i]);
                std::cout << std::setw(length) << row[i];
            }

        }
        std::cout << std::endl;
    }

    //mysql_free_result(result);
    result = nullptr;
    return table;
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
