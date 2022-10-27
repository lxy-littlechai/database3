//
// Created by 16117 on 2022/10/26.
//
#include "DatabaseManager.h"
#include "BusManager.h"
#include <cstdio>

char query[1500];

BusManager::BusManager() {
    sprintf(query,"create table if not exists bus\n"
                  "(\n"
                  "    location varchar(10) not null\n"
                  "        primary key,\n"
                  "    price    int         null,\n"
                  "    numSeats   int         null,\n"
                  "    numAvail int         null\n"
                  ");\n"
                  "");
    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;

    if(mysql_query(mysql, query)) {
        printf("Create Bus Failed!\n%s", mysql_error(mysql));
        return ;
    } else {
        printf("Create Bus Successs!\n");
    }
}

void BusManager::input() {
    std::cin >> location >> price >> numSeats;
}

void BusManager::insert() {
    std::sprintf(query, "insert into bus values('%s',%d,%d,0);", location.c_str(),price,numSeats);

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Insert Bus Failed!(%s)\n", mysql_error(mysql));
        return ;
    } else {
        printf("Insert Bus Successs!\n");
    }
}

void BusManager::update() {
    std::sprintf(query, "update bus set numAvail=numAvail-1 where location='%s'; ", location.c_str());

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Update Bus Failed!\n%s", mysql_errno(mysql));
        return ;
    } else {
        printf("Update Bus Successs!\n");
    }
}