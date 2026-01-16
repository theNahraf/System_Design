#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include "../models/Cart.h"
#include "../models/Restaurant.h"
#include "../models/Order.h"
#include "../strategies/PaymentStrategy.h"
#include <bits/stdc++.h>
using namespace std;

class OrderFactory{
public:
    virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuitems, 
                                PaymentStrategy* PaymentStrategy, const string & ordertype) = 0;
    
    virtual ~OrderFactory() {}
};
#endif

