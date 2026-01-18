#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include "Order.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

class DeliveryOrder : public Order{
private:
    string userAddress;
public:
    DeliveryOrder(){
        userAddress = "";
    }

    string getType() const override{
        return "Delivery";
    }
    //getttere setters
    void setUserAddress(const string & add){
        userAddress = add;
    }
    string getUserAddress() const {
        return userAddress;
    }
};

#endif