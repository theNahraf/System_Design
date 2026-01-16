#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <bits/stdc++.h>
#include"Menu.h"
using namespace std;

using ll = long long;
using pii = pair<int, int>;

class Restaurant{
private:  
    static int nextRestaurantId;
    int restaurantId;
    string name;
    string location;
    vector<MenuItem> menu;

public:
    Restaurant(const string& name, const string& location){
        this->name = name;
        this->location = location;
        restaurantId = ++nextRestaurantId;
    }

    string getName() const{
        return name;
    }
    void setName(const string &n){
        name = n;
    }
    string getLocation() const{
        return  location;
    }
    void setLocation(const string & loc){
        location = loc;
    }
    void addMenuItem(const  MenuItem& item){
        menu.push_back(item);
    }
    const vector<MenuItem> & getMenu() const{
        return menu;
    }
    ~Restaurant(){
        cout<<"restraunt is deleted , distructor is called"<<endl;
    }

};
int Restaurant::nextRestaurantId = 0;

#endif