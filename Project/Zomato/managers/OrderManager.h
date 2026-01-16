#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <bits/stdc++.h>
#include "../models/Order.h"
using namespace std;

class OrderManager{
private:    
    vector<Order*> orders;
    static OrderManager* instance;
    OrderManager(){
        //private constructor
    }
public:
    static OrderManager* getIntance(){
        if(!instance){
            instance =  new OrderManager();
        }
        return instance;
    }

    void addOrder(Order * order){
        orders.push_back(order);
    }

    void listOrder(){
        cout<<"\n ----- ALL ORDERS -------"<<endl;
        for(auto order: orders){
            cout<<order->getType() << "Order for " << order->getUser()->getName()
            << "  |  Total : rs "<< order->getTotal()
            << " | At: " << "order->getScheduled()" <<endl;
        }
    } 
};
OrderManager* OrderManager::instance = nullptr;

#endif