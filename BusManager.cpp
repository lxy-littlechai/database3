//
// Created by 16117 on 2022/10/26.
//
#include "DatabaseManager.h"
#include "BusManager.h"
#include <cstdio>

extern char query[1500];

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
    printf("请依次输入位置 价格 座位数\n");
    std::cin >> location >> price >> numSeats;
}

void BusManager::insert() {
    std::sprintf(query, "insert into bus values('%s',%d,%d,%d);", location.c_str(),price,numSeats,numSeats);

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Insert Bus Failed!(%s)\n", mysql_error(mysql));
        return ;
    } else {
        printf("Insert Bus Successs!\n");
    }
}

std::string BusManager::reserve() {
    printf("请选择要预定的大巴位置\n");

    std::cin >> location;
    show();
    std::sprintf(query, "update bus set numAvail=numAvail-1 where location='%s'; ", location.c_str());

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Reserve Bus Failed!\n%s", mysql_errno(mysql));
        return "Failed";
    } else {
        printf("Reserve Bus Successs!\n");
        return location;
    }
}


void BusManager::show() {
    std::sprintf(query, "select * from bus");
    MYSQL *mysql = &DatabaseManager::getInstance()->mysql;
    if (!mysql_query(mysql, query)) {
        DatabaseManager::getInstance()->result = mysql_store_result(mysql);
        DatabaseManager::getInstance()->showTable();
    }

}