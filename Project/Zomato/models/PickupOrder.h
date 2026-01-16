#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include "Order.h"
#include <bits/stdc++.h>
using namespace std;

class PickupOrder : public Order{
private:
    string userAddress;
public:
    PickupOrder(){
        userAddress = "";
    }

    string getType() const override{
        return "Pickup";
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