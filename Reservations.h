//
// Created by 16117 on 2022/10/27.
//

#include <iostream>
#include <iomanip>
#ifndef DATABASE3_RESERVATIONS_H
#define DATABASE3_RESERVATIONS_H


class Reservations {
public:
    Reservations(std::string,int,std::string);
    void insert();
    static void show();
    static void lookupCustomer();

private:
    std::string custName;
    int resvType;
    std::string resvKey;
    std::string travelKey;
};


#endif //DATABASE3_RESERVATIONS_H
