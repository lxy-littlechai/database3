//
// Created by 16117 on 2022/10/27.
//

#include <cstring>
#include "Reservations.h"
#include "DatabaseManager.h"

extern char query[1500];

Reservations::Reservations(std::string custName, int resvType, std::string travelKey) {
    this->custName = custName;
    this->resvType = resvType;
    this->travelKey = travelKey;
}

void Reservations::insert() {
        std::sprintf(query, "insert into reservation values('%s',%d,NULL,'%s');", custName.c_str(), resvType, travelKey.c_str());

        MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
        if(mysql_query(mysql, query)) {
            printf("Insert Reservation Failed!(%s)\n", mysql_error(mysql));
            return ;
        } else {
            printf("Insert Reservation Successs!\n");
        }
}

void Reservations::lookupCustomer() {
    std::string custName;
    printf("请输入要查询的客户姓名");
    std::cin >> custName;

    std::sprintf(query, "select resvType,travelKey from reservation where custname='%s';",custName.c_str());
    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(!mysql_query(mysql, query)) {
        DatabaseManager::getInstance()->result = mysql_store_result(mysql);

        printf("该客户的预定信息如下\n");
        auto vec = DatabaseManager::getInstance()->showTable();

        for(int i = 1;i < vec.size();i ++) {
            auto resvType = vec[i][0];
            auto travelKey = vec[i][1];
            if(strcmp(resvType, "1") == 0) {
                std::sprintf(query, "select location from flights where flightNum='%s';",travelKey);
            } else if(strcmp(resvType, "2") == 0) {
                std::sprintf(query, "select location from hotel where location='%s';",travelKey);
            } else if(strcmp(resvType, "3") == 0) {
                std::sprintf(query, "select location from bus where location='%s';",travelKey);
            }
            if(!mysql_query(mysql, query)) {
                DatabaseManager::getInstance()->result = mysql_store_result(mysql);
                DatabaseManager::getInstance()->showTable(false);
            }
        }
    }




}

void Reservations::show() {
    std::sprintf(query, "select * from reservation");
    MYSQL* mysql = &DatabaseManager::getInstance()->mysql;
    if(!mysql_query(mysql, query)) {
        DatabaseManager::getInstance()->result = mysql_store_result(mysql);
        DatabaseManager::getInstance()->showTable();
    }
}