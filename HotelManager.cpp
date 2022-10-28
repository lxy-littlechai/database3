//
// Created by 16117 on 2022/10/27.
//

#include "HotelManager.h"
#include "DatabaseManager.h"
#include <cstdio>

extern char query[1500];

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
    printf("请依次输入位置 价格 房间数\n");
    std::cin >> location >> price >> numSeats;
}

void HotelManager::insert() {
    std::sprintf(query, "insert into hotel values('%s',%d,%d,%d);", location.c_str(),price,numSeats,numSeats);

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Insert Hotel Failed!(%s)\n", mysql_error(mysql));
        return ;
    } else {
        printf("Insert Hotel Successs!\n");
    }
}

std::string HotelManager::reserve() {
    printf("请选择要预定的酒店位置\n");
    show();
    std::cin >> location;

    std::sprintf(query, "update hotel set numAvail=numAvail-1 where location='%s'; ", location.c_str());

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Reserve Hotel Failed!\n%s", mysql_errno(mysql));
        return "Failed";
    } else {
        printf("Reserve Hotel Successs!\n");
        return location;
    }
}

void HotelManager::show() {
    std::sprintf(query, "select * from hotel");
    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(!mysql_query(mysql, query)) {
        DatabaseManager::getInstance()->result = mysql_store_result(mysql);
        DatabaseManager::getInstance()->showTable();
    }
}