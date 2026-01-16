#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include "Order.h"
#include <bits/stdc++.h>
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