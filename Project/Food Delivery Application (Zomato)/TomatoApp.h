#ifndef TOMATO_APP_H
#define TOMATO_APP_H

#include "models/Restaurant.h"
#include "models/Menu.h"
#include "managers/RestaurantManager.h"
#include "models/User.h"
#include "strategies/PaymentStrategy.h"
#include "models/Order.h"
#include "factories/OrderFactory.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

#include "managers/OrderManager.h"
#include "services/NotificationService.h"
#include "strategies/UpiPaymentStrategy.h"
#include "strategies/CreditCartPaymentStrategy.h"
using namespace std;


class TomatoApp{
public:
    TomatoApp(){
        initializeRestaurants();
    }

    void initializeRestaurants(){
        Restaurant* res1 =  new Restaurant("Bikari", "Delhi");
        res1->addMenuItem(MenuItem("P1", "Chole Bhature", 120));      
        res1->addMenuItem(MenuItem("P2", "Samosa", 15));    
        
        
        Restaurant* res2 =  new Restaurant("Haldiram", "Kolkata");
        res2->addMenuItem(MenuItem("P1", "Raj Kachori", 80));      
        res2->addMenuItem(MenuItem("P2", "Pav", 100));    
        res2->addMenuItem(MenuItem("P3", "Dhokla bhaji", 50));    
        
        
        Restaurant* res3 =  new Restaurant("Sarvana Bhavan", "Chennai");
        res3->addMenuItem(MenuItem("P1", "Masala Dosa", 90));      
        res3->addMenuItem(MenuItem("P2", "Idli Vada", 60));    
        res3->addMenuItem(MenuItem("P2", "Idli Vada", 30)); 
        
        RestaurantManager * restaurantManager = RestaurantManager::getInstance();
        restaurantManager->addRestaurant(res1);
        restaurantManager->addRestaurant(res2);
        restaurantManager->addRestaurant(res3);
       }

vector<Restaurant*> searchRestaurants(const string & location){
    return RestaurantManager::getInstance()->searchByLocation(location);
}



void selectRestaurants(User* user, Restaurant* res){
    Cart* cart = user->getCart();
    cart->setRestaurants(res); 
}

void addToCart(User* user, const string & itemcode){
    Restaurant* restaurant = user->getCart()->getRestaurants();
    if(!restaurant){
        cout<<"Plese select a restaurant first "<<endl;
        return ;
    }
    for(const auto & item : restaurant->getMenu()){
        if(item.getCode() == itemcode){
            user->getCart()->addItems(item);
            break;
        }
    }
}

Order* checkoutNow(User* user, const string& orderType,
    PaymentStrategy * paymentStrategy){
        return checkout(user, orderType, paymentStrategy, new NowOrderFactory());
    }
Order* checkoutScheduled(User* user, const string& orderType,
    PaymentStrategy * paymentStrategy, const string& scheduleTime){
        return checkout(user, orderType, paymentStrategy, new ScheduledOrderFactory(scheduleTime));
    }

    Order* checkout(User* user, const string & orderType, 
        PaymentStrategy* paymentStrategy,OrderFactory* orderFactory){

        if(user->getCart()->isEmpty()) return nullptr;
    
        Cart* userCart  = user->getCart();
        Restaurant* orderdRestaurant = userCart->getRestaurants();
        vector<MenuItem> itemsOrdered = userCart->getItems();
        double totalCost = userCart->getTotalCost();

        Order* order= orderFactory->createOrder(user, userCart, orderdRestaurant, itemsOrdered, paymentStrategy, totalCost, orderType);
        OrderManager::getInstance()->addOrder(order);
        return order;
        }


    void payForOrder(User* user, Order* order){
        bool isPaymentSuccess = order->processPayment();  
        // clear user cart if payment is successful.
        if(isPaymentSuccess) {
            NotificationService* notification = new NotificationService();
            notification->notify(order);
            user->getCart()->clear();
        }  
    }

    void printUserCart(User* user) {
        cout << "Items in cart:" << endl;
        cout << "------------------------------------" << endl;
        for (auto item : user->getCart()->getItems()) {
            cout << item.getCode() << " : " << item.getName() << " : ₹" << item.getPrice() << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total : ₹" << user->getCart()->getTotalCost() << endl;
    }
    
};

#endif