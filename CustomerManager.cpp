//
// Created by 16117 on 2022/10/27.
//

#include "CustomerManager.h"
#include "DatabaseManager.h"
#include <cstdio>

char query[1500];
CustomerManager::CustomerManager() {
    sprintf(query,"create table if not exists customers\n"
                  "(\n"
                  "    custName varchar(10) not null\n"
                  "        primary key,\n"
                  "    custID   varchar(10) null\n"
                  ");\n"
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
    std::sprintf(query, "insert into customers values('%s');", custName.c_str());

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Insert Hotel Failed!(%s)\n", mysql_error(mysql));
        return ;
    } else {
        printf("Insert Hotel Successs!\n");
    }
}

void CustomerManager::input() {
    std::cin >> custName;
}

