#ifndef MENUITEM_H
#define MENUITEM_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
class MenuItem{
private:
    string code;
    string name;
    double price;
public:
    MenuItem(const string& code, const string&name, double price){
        this->code = code;
        this->name =  name;
        this->price =  price;
    }

    string getCode() const{
        return code;
    }
    void setCode(const string & c){
        code = c;
    }

    string getName() const{
        return name;
    }    
    void setName(const string & n){
        name =  n;
    }
    double getPrice(){
        return price;
    }
    void setPrice(double p){
        price =  p;
    }
  
};

#endif