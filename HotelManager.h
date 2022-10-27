//
// Created by 16117 on 2022/10/27.
//
#include <iostream>
#include <string>
#ifndef DATABASE3_HOTELMANAGER_H
#define DATABASE3_HOTELMANAGER_H


class HotelManager {
private:
    HotelManager();
    void insert();
    void update();
    void input();

    std::string location;
    int price;
    int numSeats;
    int numAvail;
};


#endif //DATABASE3_HOTELMANAGER_H
