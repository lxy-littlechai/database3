#include <iostream>
#include "DatabaseManager.h"
#include "FlightsManager.h"
#include "BusManager.h"
#include "HotelManager.h"
#include "CustomerManager.h"
#include "Reservations.h"
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

extern char query[1500];
int main() {

    if(DatabaseManager::getInstance()->connectMySQL()) {
//        FlightsManager flightsManager;
//        BusManager busManager;
//        HotelManager hotelManager;
//        CustomerManager customerManager;

        int operation;
        while(true) {
            memset(query,'\0',sizeof(query));
            printf("请输入您的操作\n"
                   "1、创建新航班\n"
                   "2、创建新大巴车\n"
                   "3、创建酒店\n"
                   "4、创建用户\n"
                   "5、预定\n"
                   "6、查询航班信息\n"
                   "7、查询大巴信息\n"
                   "8、查询宾馆信息\n"
                   "9、查询客户信息\n"
                   "10、查询预定信息\n"
                   "11、查询顾客旅行线路\n");

            std::cin >> operation;
//            switch (operation) {
//                case 1:{
//                    flightsManager.input();
//                    flightsManager.insert();
//                    break;
//                }
//                case 2: {
//                    busManager.input();
//                    busManager.insert();
//                    break;
//                }
//                case 3: {
//                    hotelManager.input();
//                    hotelManager.insert();
//                    break;
//                }
//                case 4: {
//                    customerManager.input();
//                    customerManager.insert();
//                    break;
//                }
//                case 5: {
//                    int resvType;
//                    std::string travelKey = "Failed";
//                    customerManager.input();
//                    if(!customerManager.check()) {
//                        customerManager.insert();
//                    }
//                    printf("请输入预定内容 1-航班 2-宾馆 3-大巴车\n");
//                    std::cin >> resvType;
//                    switch (resvType) {
//                        case 1: {
//                            travelKey = flightsManager.reserve();
//                            break;
//                        }
//                        case 2: {
//                            travelKey = hotelManager.reserve();
//                            break;
//                        }
//                        case 3: {
//                            travelKey = busManager.reserve();
//                            break;
//                        }
//                    }
//
//                    if(travelKey != "Failed") {
//                        Reservations reservation(customerManager.getName(), resvType, travelKey);
//                        reservation.insert();
//                    }
//                }
//                case 6: {FlightsManager::show(); break;}
//                case 7: {BusManager::show(); break;}
//                case 8: {HotelManager::show(); break;}
//                case 9: {CustomerManager::show(); break;}
//                case 10: {Reservations::show(); break;}
//                case 11: {Reservations::lookupCustomer();break;}
//            }


        }


        DatabaseManager::getInstance()->closeMySQL();
    }



    return 0;
}

#pragma clang diagnostic pop