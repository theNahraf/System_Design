#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

//notification and decorators

class INotification{
public:
    virtual string getContent() const= 0;
    virtual ~INotification() {};
};


//concreate noitifcqation simple text notification
class SimpleNotifcation : public INotification {
private:
    string text;
public:
    SimpleNotifcation(const string & msg){
        text = msg;
    }
    string getContent() const override {
        return text;
    }
};

// abstract decorator : wraps a notifcation object

class INotificationDecorator : public INotification{
protected:
    INotification* notification;
public:
    INotificationDecorator(INotification* n){
        notification = n;
    }

    virtual ~INotificationDecorator() {
        delete notification;
    }
};

//concrete decorator to add timestapmp 
class TimeStampDecorator : public INotificationDecorator {   
public:
    TimeStampDecorator(INotification*n): INotificationDecorator(n){}

    string getContent() const override{
        return "[2025-01-01 12:00:00] " + notification->getContent();
    }
};

//decorator to append a signatire to the contnet:
class SignatureDecorator : public INotificationDecorator{
public:
    SignatureDecorator(INotification* n) : INotificationDecorator(n){}
    string getContent() const override {
        return notification->getContent() + "\n\nBest Regards,\nNotification System";
    }
};



// observer pattern components

class IObserver {
public:
    virtual void update() = 0;
    virtual ~IObserver() {}
};

class IObservable{
public:
    virtual void addObserver(IObserver* observer) =0;
    virtual void removeObserver(IObserver* observer) = 0;
    virtual void notifyObservers() = 0;
};

//concreqate observale 
class NotificationObservable : public IObservable {
private:
    vector<IObserver*> observers;
    INotification* currentNotification;
public:
    NotificationObservable(){
        currentNotification = nullptr;
    }
    void addObserver(IObserver* obs) override {
        if (obs) {
            observers.push_back(obs);
        }
    }
    void removeObserver(IObserver * obs) override {
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void notifyObservers() override {
        for(auto& obs : observers) {
            obs->update();
        }
    }
    void setNotificatoin(INotification * notification){
        if(currentNotification != nullptr){
            delete currentNotification; // Clean up previous notification
        }
        currentNotification = notification;
        notifyObservers();
    }

    INotification *getNotification(){
        return currentNotification;
    } 
     string getNotificationContent() {
        if (currentNotification) {
            return currentNotification->getContent();
        }
        return "No notification set.";
    }

    ~NotificationObservable(){
        if(currentNotification != NULL)
            delete currentNotification;
    }

};


// concreate observer 
class Logger : public IObserver{
private:
    NotificationObservable*  notificationObservable;
public:
    Logger(NotificationObservable* observable){
        this->notificationObservable = observable;
    }
    void update() override{
        cout<< "Logging New Notification: \n" << notificationObservable->getNotificationContent();
    }
};




int main() {

    return 0;
}