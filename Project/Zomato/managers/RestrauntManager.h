#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H
#include <bits/stdc++.h>
#include "../models/Restaurant.h"
using namespace std;


class RestrauntManager{
private:
    vector<Restaurant*> restaurants; 
    static RestrauntManager*  instance;
    // SINGLETONE CLASS
    RestrauntManager(){
        //private constructor
    }

public:
    static RestrauntManager * getInstance(){
        if(!instance){
            instance =  new RestrauntManager();
        }
        return instance;
    }

    void addRestaurant(Restaurant* r){
        restaurants.push_back(r);
    }
    
    vector<Restaurant*> searchByLocation(string & loc){
        vector<Restaurant*> result;
        transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
        for(auto r : restaurants){
            string rl = r->getLocation();
            transform(rl.begin(), rl.end(), rl.begin(),  ::tolower);
            if(rl == loc) result.push_back(r);
        }
        return result;
    }

};

RestrauntManager* RestrauntManager::instance = nullptr;


#endif