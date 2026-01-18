#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H
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

class CreditCardPaymentStrategy : public PaymentStrategy{
private:    
    string cardNumber;
    string name;

public:
    CreditCardPaymentStrategy(const string &card, const string& name){
        this->cardNumber =  card;
        this->name = name;
    }

    void Pay(double amount) override { 
        cout<< "Paid Rs "<< amount << " using Credit Card Number -> ("<<cardNumber<<")" << "& holder Name -> "<<name<<endl;
    }

};

#endif