//
// Created by 16117 on 2022/10/26.
//

#include "DatabaseManager.h"
#include "FlightsManager.h"
#include <cstdio>

char query[1500];
FlightsManager::FlightsManager() {
//( numAvail >= 0 ) constraint BusNotEmpty
    sprintf(query, "create table if not exists flights\n"
                   "(\n"
                   "    fightNum varchar(10) not null\n"
                   "    primary key              ,\n"
                   "    price    int         null,\n"
                   "    numSeats int         null,\n"
                   "    numAvail int         null,\n"
                   "    FromCity varchar(10) null,\n"
                   "    ArivCity varchar(10) null,\n"
                   "    check(numAvail > 0)       \n"
                   ");\n"
                   "");

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Create Flights Failed!\n%s", mysql_error(mysql));
        return ;
    } else {
        printf("Create Flights Successs!\n");
    }
}

void FlightsManager::input() {
    std::cin >> flightNum >> price >> numSeats >> FromCity >> ArivCity;
}

void FlightsManager::insert() {
    std::sprintf(query, "insert into flights values('%s',%d,%d,0,'%s','%s');", flightNum.c_str(),price,numSeats,FromCity.c_str(),ArivCity.c_str());

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Insert Flights Failed!(%s)\n", mysql_error(mysql));
        return ;
    } else {
        printf("Insert Flights Successs!\n");
    }
}

void FlightsManager::update() {
    std::sprintf(query, "update flights set numAvail=numAvail-1 where fightNum='%s'; ", flightNum.c_str());

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Update Flights Failed!\n%s", mysql_errno(mysql));
        return ;
    } else {
        printf("Update Flights Successs!\n");
    }
}
