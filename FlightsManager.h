//
// Created by 16117 on 2022/10/26.
//
#include <iostream>
#include <string>
#include <iomanip>
#ifndef DATABASE3_FLIGHTSMANAGER_H
#define DATABASE3_FLIGHTSMANAGER_H


class FlightsManager {
public:
    FlightsManager();
    void insert();
    std::string reserve();
    static void show();
    void input();

private:
    std::string flightNum;
    int price;
    int numSeats;
    int numAvail;
    std::string FromCity;
    std::string ArivCity;
};


#endif //DATABASE3_FLIGHTSMANAGER_H
