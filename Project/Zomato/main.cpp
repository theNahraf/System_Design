#include <bits/stdc++.h>
using namespace std;
#include "TomatoApp.h"


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //create Tomato app facade
    TomatoApp* tomato =  new TomatoApp();

    //simulate a user coming in happy flow

    User* user = new User(101, "Farhan", "Delhi");
    cout<<"User: "<<user->getName()<<" is active"<<endl;
    
    //user search restaurants by location 

    vector<Restaurant*> restaurantList = tomato->searchRestaurants("Delhi");

    if(restaurantList.empty()){
        cout<<"No Restaurants Found! "<<endl;
        return 0; 
    }

    cout<<"Found Restaurants : "<<endl;
    for(auto restaurant: restaurantList){
        cout<< " - "<<restaurant->getName()<<endl;
    }

    //user selecte a restaurants
    tomato->selectRestaurants(user, restaurantList[0]);
    cout<< "Selected Restaurants "<< restaurantList[0]->getName() << endl;
    

    //user add items to the cart
    tomato->addToCart(user, "P1");
    tomato->addToCart(user, "P2");

    tomato->printUserCart(user);

    //user  chekcout the cart
    Order* order =  tomato->checkoutNow(user, "Delivery", new UpiPaymentStrategy("9871314606"));
  

    //user pay for the cart , if payment success, notification is sent
    tomato->payForOrder(user, order);
    
    delete tomato;
    delete user;
    
    return 0;
}