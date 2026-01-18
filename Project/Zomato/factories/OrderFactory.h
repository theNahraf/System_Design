#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include "../models/Cart.h"
#include "../models/Restaurant.h"
#include "../models/Order.h"
#include "../strategies/PaymentStrategy.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

class OrderFactory{
public:
    virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuitems, 
                                PaymentStrategy* PaymentStrategy,double totalCost, const string & orderType) = 0;
    
    virtual ~OrderFactory() {}
};
#endif

