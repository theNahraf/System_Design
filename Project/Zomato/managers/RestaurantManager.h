#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

#include "../models/Restaurant.h"
using namespace std;


class RestaurantManager{
private:
    vector<Restaurant*> restaurants; 
    static RestaurantManager*  instance;
    // SINGLETONE CLASS
    RestaurantManager(){
        //private constructor
    }

public:
    static RestaurantManager * getInstance(){
        if(!instance){
            instance =  new RestaurantManager();
        }
        return instance;
    }

    void addRestaurant(Restaurant* r){
        restaurants.push_back(r);
    }
    
vector<Restaurant*> searchByLocation(const string & loc){
    vector<Restaurant*> result;

    string lowerLoc = loc;
    transform(lowerLoc.begin(), lowerLoc.end(), lowerLoc.begin(), ::tolower);

    for(auto r : restaurants){
        string rl = r->getLocation();
        transform(rl.begin(), rl.end(), rl.begin(), ::tolower);

        if(rl == lowerLoc)
            result.push_back(r);
    }

    return result;
}


};

RestaurantManager* RestaurantManager::instance = nullptr;


#endif