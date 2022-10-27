//
// Created by 16117 on 2022/10/26.
//

#include "DatabaseManager.h"
#include "FlightsManager.h"
#include <cstdio>

extern char query[1500];
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
    printf("请依次输入航班号 价格 座位数 起点 终点\n");
    std::cin >> flightNum >> price >> numSeats >> FromCity >> ArivCity;
}

void FlightsManager::insert() {
    std::sprintf(query, "insert into flights values('%s',%d,%d,%d,'%s','%s');", flightNum.c_str(),price,numSeats,numSeats,FromCity.c_str(),ArivCity.c_str());

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Insert Flights Failed!(%s)\n", mysql_error(mysql));
        return ;
    } else {
        printf("Insert Flights Successs!\n");
    }
}

std::string FlightsManager::reserve() {
    printf("请选择要预定的航班号\n");
    show();
    std::cin >> flightNum;

    std::sprintf(query, "update flights set numAvail=numAvail-1 where fightNum='%s'; ", flightNum.c_str());

    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(mysql_query(mysql, query)) {
        printf("Reserve Flights Failed!\n%s", mysql_errno(mysql));
        return "Failed";
    } else {
        printf("Reserve Flights Successs!\n");
        return flightNum;
    }
}

void FlightsManager::show() {
    std::sprintf(query, "select * from flights");
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
