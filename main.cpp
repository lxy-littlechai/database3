#include <iostream>
#include "DatabaseManager.h"
#include "FlightsManager.h"
#include "BusManager.h"
#include "CustomerManager.h"
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
int main() {

    if(DatabaseManager::getInstance()->connectMySQL()) {
        FlightsManager flightsManager;
        BusManager busManager;
        CustomerManager customerManager;
        int operation;
        while(true) {
            printf("请输入您的操作\n"
                   "1、创建新航班\n"
                   "2、创建新大巴车\n"
                   "3、创建酒店\n"
                   "4、创建用户\n");

            std::cin >> operation;
            switch (operation) {
                case 1:{
                    printf("请依次输入航班号 价格 座位数 起点 终点\n");
                    flightsManager.input();
                    flightsManager.insert();
                    break;
                }
                case 2: {
                    printf("请依次输入位置 价格 座位数\n");
                    busManager.input();
                    busManager.insert();
                    break;
                }
                case 3: {
                    printf("请依次输入位置 价格 座位数\n");
                    busManager.input();
                    busManager.insert();
                    break;
                }
                case 4: {
                    printf("用户名\n");
                    customerManager.input();
                    customerManager.insert();
                    break;
                }

            }


        }


        DatabaseManager::getInstance()->closeMySQL();
    }



    return 0;
}

#pragma clang diagnostic pop