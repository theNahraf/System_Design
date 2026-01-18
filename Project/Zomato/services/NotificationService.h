#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include "../models/Order.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

class NotificationService{
public:
    static void notify(Order* order){
         cout << "\nNotification: New " << order->getType() << " order placed!" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Order ID: " << order->getOrderId() << endl;
        cout << "Customer: " << order->getUser()->getName() << endl;
        cout << "Restaurant: " << order->getRestaurant()->getName() << endl;
        cout << "Items Ordered:\n";

        const vector<MenuItem>& items = order->getItems();
        for (auto item : items) {
            cout << "   - " << item.getName() << " (₹" << item.getPrice() << ")\n";
        }

        cout << "Total: ₹" << order->getTotal() << endl;
        cout << "Scheduled For: " << order->getScheduled() << endl;
        cout << "Payment: Done" << endl;
        cout << "---------------------------------------------" << endl;
    }
};

#endif