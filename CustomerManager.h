//
// Created by 16117 on 2022/10/27.
//

#include <iostream>
#include <iomanip>
#ifndef DATABASE3_CUSTOMERMANAGER_H
#define DATABASE3_CUSTOMERMANAGER_H


class CustomerManager {
public:
    CustomerManager();
    void insert();
    bool check();
    void input();
    std::string getName();
    static void show();
private:
    std::string custName;
    std::string custID;
};


#endif //DATABASE3_CUSTOMERMANAGER_H
