#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;


 
class PaymentStrategy{
public:
    virtual void Pay(double amount) = 0;
    virtual ~PaymentStrategy(){}
};

#endif