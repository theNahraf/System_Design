#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H
#include "PaymentStrategy.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

class UpiPaymentStrategy : public PaymentStrategy{
private:    
    string mobile;
public:
    UpiPaymentStrategy(const string &mob){
        this->mobile = mob;
    }

    void Pay(double amount) override { 
        cout<< "Paid Rs "<< amount << " using UPI ("<<mobile<<")"<<endl;
    }

};

#endif