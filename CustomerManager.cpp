//
// Created by 16117 on 2022/10/27.
//

#include "CustomerManager.h"
#include "DatabaseManager.h"
#include <cstdio>

extern char query[1500];
CustomerManager::CustomerManager() {
    sprintf(query,"create table if not exists customers\n"
                  "(\n"
                  "custID   int auto_increment\n"
                  "        primary key,\n"
                  "    custName varchar(10) not null,\n"
                  "    constraint customers_custName_uindex\n"
                  "        unique (custName)"
                  "");

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;

    if(mysql_query(mysql, query)) {
        printf("Create Customer Failed!\n%s", mysql_error(mysql));
        return ;
    } else {
        printf("Create Customer Successs!\n");
    }
}

void CustomerManager::insert() {
    std::sprintf(query, "insert into customers values(NULL,'%s');", custName.c_str());

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Insert customers Failed!(%s)\n", mysql_error(mysql));
        return ;
    } else {
        printf("Insert customers Successs!\n");
    }
}

bool CustomerManager::check() {
    std::sprintf(query, "insert into customers values('%s');",custName.c_str());
    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        return false;
    } else {
        return true;
    }
}

void CustomerManager::input() {
    printf("请输入姓名\n");
    std::cin >> custName;
}

std::string CustomerManager::getName() {
    return custName;
}

void CustomerManager::show() {
    std::sprintf(query, "select * from customers");
    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(!mysql_query(mysql, query)) {
        MYSQL_RES *result = mysql_store_result(mysql);
        int column = mysql_num_fields(result);
        MYSQL_FIELD *field = nullptr;
        int length = 12;

        while((field = mysql_fetch_field(result))) {
            std::cout << std::setw(length) << field->name;
        }
        std::cout << std::endl;

        MYSQL_ROW row;
        while((row = mysql_fetch_row(result))) {
            for(int i = 0;i < column;i ++) {
                if(row[i] == NULL) {
                    std::cout << std::setw(length) << "NULL";
                } else {
                    std::cout << std::setw(length) << row[i];
                }

            }
            std::cout << std::endl;
        }
        mysql_free_result(result);
    }
}

