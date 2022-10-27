//
// Created by 16117 on 2022/10/26.
//
#include <iostream>
#include <string>
#ifndef DATABASE3_FLIGHTSMANAGER_H
#define DATABASE3_FLIGHTSMANAGER_H


class FlightsManager {
public:
    FlightsManager();
    void insert();
    void update();
    void input();

    std::string flightNum;
    int price;
    int numSeats;
    int numAvail;
    std::string FromCity;
    std::string ArivCity;
};


#endif //DATABASE3_FLIGHTSMANAGER_H
