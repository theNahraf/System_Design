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
    void setRestaurantAddress(const string & add){
        userAddress = add;
    }
    string getRestaurantAddress() const {
        return userAddress;
    }
};

#endif