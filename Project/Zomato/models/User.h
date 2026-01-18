#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

#include "Restaurant.h"
#include "Cart.h"
using namespace std;

class User{
private:
    int userId;
    string name;
    string address;
    Cart* cart;

public:
    User(int id, const string & name, const string & add){
        this->userId = id;
        this->name =  name;
        this->address =  add;
        cart = new Cart();
    }

    ~User(){
        
        delete cart;
    }

    string getName() const{
        return name;
    }

    string getAddress() const{
        return address;
    }

    Cart* getCart(){
        return cart;
    }

};

#endif