#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

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