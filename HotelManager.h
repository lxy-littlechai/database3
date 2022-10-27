//
// Created by 16117 on 2022/10/27.
//
#include <iostream>
#include <string>
#include <iomanip>
#ifndef DATABASE3_HOTELMANAGER_H
#define DATABASE3_HOTELMANAGER_H


class HotelManager {
public:
    HotelManager();
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


#endif //DATABASE3_HOTELMANAGER_H
