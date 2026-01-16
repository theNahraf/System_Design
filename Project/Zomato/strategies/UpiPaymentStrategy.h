#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H
#include "PaymentStrategy.h"
#include <bits/stdc++.h>
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