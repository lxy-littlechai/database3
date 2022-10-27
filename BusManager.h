//
// Created by 16117 on 2022/10/26.
//
#include <iostream>
#include <string>
#include <iomanip>
#ifndef DATABASE3_BUSMANAGER_H
#define DATABASE3_BUSMANAGER_H


class BusManager {
public:
    BusManager();
    void insert();
    std::string reserve();
    static void show();
    void input();

private:
    std::string location;
    int price;
    int numSeats;
    int numAvail;
};


#endif //DATABASE3_BUSMANAGER_H
