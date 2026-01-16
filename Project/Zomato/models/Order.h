#ifndef ORDER_H
#define ORDER_H


#include "Restaurant.h"
#include "User.h"
#include "Menu.h"
#include "../strategies/PaymentStrategy.h"
#include <bits/stdc++.h>
using namespace std;

class Order{
private:
    static int nextOrderId;
    int orderId;
    Restaurant * restaurant;
    User * user;
    vector<MenuItem> items;
    PaymentStrategy* paymentSrategy;
    double total;
    string scheduled;

public: 
    Order(){
        user = nullptr;
        restaurant = nullptr;
        paymentSrategy = nullptr;
        total = 0.0;
        scheduled = "";
        orderId = ++nextOrderId;
    }

    virtual ~Order(){
        delete paymentSrategy;
    }
    
    virtual string getType()  const  = 0;

    //Getter and Setters
    
    int getOrderId() const{
        return orderId;
    }

    void setUser(User* u){
        user = u;
    }
    User* getUser() const{
        return user;
    }

    void setRestaurant(Restaurant* r){
        restaurant = r;
    }
    Restaurant* getRestaurant() const {
        return restaurant;
    }

    void setItems(const vector<MenuItem>& its){
        items = its;
        total = 0;
        for(auto & i : items){
            total+=i.getPrice();
        }
    }

    const vector<MenuItem>& getItems() const{
        return items;
    }

    void setPaymentStrategy(PaymentStrategy *p){
        paymentSrategy = p;
    }
    
    double getTotal(){
        double sum = 0;
        for(auto it : items){
            sum+= it.getPrice();
        }
        return sum;
    }

    void setTotal(double p){
        total = p;
    }

    
    void setScheduled(const string& s) {
        scheduled = s;
    }

    string getScheduled() const {
        return scheduled;
    }

};

int Order::nextOrderId = 0;



#endif