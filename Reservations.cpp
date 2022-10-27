//
// Created by 16117 on 2022/10/27.
//

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

void Reservations::show() {
    std::sprintf(query, "select * from reservation");
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