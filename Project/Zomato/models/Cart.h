#ifndef CART_H
#define CART_H
#include <bits/stdc++.h>
#include "Restaurant.h"
#include "Menu.h"

using namespace std;

class Cart{
private:
    Restaurant* restaurant;
    vector<MenuItem> items;

public: 
    Cart(){
        restaurant =  nullptr;
    }
    void addItems(const MenuItem& item){
        if(!restaurant){
            cout<<"Cart : set a restaurant before adding items. "<<endl;
            return ;
        }
        items.push_back(item);
    }

    double getTotalCost() const{
        double sum = 0;
        for(auto it : items){
            sum += it.getPrice();
        }
        return sum;
    }

    void clear(){
        items.clear();
        restaurant = nullptr;
    }
    bool isEmpty(){
        return (!restaurant || items.empty());
    }

    //getter setters 
    void setRestaurants(Restaurant*r){
        restaurant =  r;
    }

    Restaurant* getRestaurants(){
        return restaurant;
    }

    const vector<MenuItem>& getItems(){
        return items;
    }

};



#endif
