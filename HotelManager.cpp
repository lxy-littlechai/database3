//
// Created by 16117 on 2022/10/27.
//

#include "HotelManager.h"
#include "DatabaseManager.h"
#include <cstdio>

char query[1500];

HotelManager::HotelManager() {
    sprintf(query,"create table if not exists hotel\n"
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
        printf("Create Hotel Failed!\n%s", mysql_error(mysql));
        return ;
    } else {
        printf("Create Hotel Successs!\n");
    }
}

void HotelManager::input() {
    std::cin >> location >> price >> numSeats;
}

void HotelManager::insert() {
    std::sprintf(query, "insert into hotel values('%s',%d,%d,0);", location.c_str(),price,numSeats);

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Insert Hotel Failed!(%s)\n", mysql_error(mysql));
        return ;
    } else {
        printf("Insert Hotel Successs!\n");
    }
}

void HotelManager::update() {
    std::sprintf(query, "update hotel set numAvail=numAvail-1 where location='%s'; ", location.c_str());

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Update Hotel Failed!\n%s", mysql_errno(mysql));
        return ;
    } else {
        printf("Update Hotel Successs!\n");
    }
}