#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H
#include "OrderFactory.h"
#include "../models/Order.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;


class ScheduledOrderFactory : public OrderFactory{
private:    
    string scheduleTime;
public:
    ScheduledOrderFactory(string scheduledTime){
        this->scheduleTime = scheduledTime;
    }
    Order* createOrder(User* user, Cart* cart, 
                    Restaurant* restaurant, 
                    const vector<MenuItem>& menuitems, 
                    PaymentStrategy* paymentStrategy, double totalCost, 
                    const string & orderType) override {

    Order* order = nullptr;                    
    if(orderType == "Delivery"){
        auto deliveryOrder = new DeliveryOrder();
        deliveryOrder->setUserAddress(user->getAddress());
        order  = deliveryOrder;
    }                        
    else{
        auto pickupOrder = new PickupOrder();
        pickupOrder->setRestaurantAddress(restaurant->getLocation());
        order = pickupOrder;
    }

    order->setUser(user);
    order->setRestaurant(restaurant);
    order->setItems(menuitems);
    order->setPaymentStrategy(paymentStrategy);
    order->setScheduled(scheduleTime);
    order->setTotal(totalCost);

    return order;
                    
      }

};

#endif
