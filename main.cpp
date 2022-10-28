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
        FlightsManager flightsManager;
        BusManager busManager;
        HotelManager hotelManager;
        CustomerManager customerManager;

        int operation;
        while(true) {
            memset(query,'\0',sizeof(query));
            printf("���������Ĳ���\n"
                   "1�������º���\n"
                   "2�������´�ͳ�\n"
                   "3�������Ƶ�\n"
                   "4�������û�\n"
                   "5��Ԥ��\n"
                   "6����ѯ������Ϣ\n"
                   "7����ѯ�����Ϣ\n"
                   "8����ѯ������Ϣ\n"
                   "9����ѯ�ͻ���Ϣ\n"
                   "10����ѯԤ����Ϣ\n"
                   "11����ѯ�˿�������·\n");

            std::cin >> operation;
            switch (operation) {
                case 1:{
                    flightsManager.input();
                    flightsManager.insert();
                    break;
                }
                case 2: {
                    busManager.input();
                    busManager.insert();
                    break;
                }
                case 3: {
                    hotelManager.input();
                    hotelManager.insert();
                    break;
                }
                case 4: {
                    customerManager.input();
                    customerManager.insert();
                    break;
                }
                case 5: {
                    int resvType;
                    std::string travelKey = "Failed";
                    customerManager.input();
                    if(!customerManager.check()) {
                        customerManager.insert();
                    }
                    printf("������Ԥ������ 1-���� 2-���� 3-��ͳ�\n");
                    std::cin >> resvType;
                    switch (resvType) {
                        case 1: {
                            travelKey = flightsManager.reserve();
                            break;
                        }
                        case 2: {
                            travelKey = hotelManager.reserve();
                            break;
                        }
                        case 3: {
                            travelKey = busManager.reserve();
                            break;
                        }
                    }

                    if(travelKey != "Failed") {
                        Reservations reservation(customerManager.getName(), resvType, travelKey);
                        reservation.insert();
                    }
                    break;
                }
                case 6: {FlightsManager::show(); break;}
                case 7: {BusManager::show(); break;}
                case 8: {HotelManager::show(); break;}
                case 9: {CustomerManager::show(); break;}
                case 10: {Reservations::show(); break;}
                case 11: {Reservations::lookupCustomer();break;}
            }


        }


        DatabaseManager::getInstance()->closeMySQL();

    }



    return 0;
}

#pragma clang diagnostic pop