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
private:
    string signature;
public:
    SignatureDecorator(INotification* n, const string & sig) : INotificationDecorator(n){
        signature = sig;
    }
    string getContent() const override {
        return notification->getContent() + "\n" + signature + "\n";
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

//strategy ppattern componenets  (concrete observer 2)

//abstract class for different notification strategies

class INotificationStrategy{
public:
    virtual void sendNotification(string content) =0;

};

class EmailStrategy : public INotificationStrategy{
    private:
    string emailId;
public:
    EmailStrategy(string emailId){
        this->emailId = emailId;
    }

    void sendNotification(string content) override {
        cout<<"sendiung email notification to " << emailId << endl;
    }
};

class SMSStrategy : public INotificationStrategy{\
private:
    string mobileNumber;
public:
    SMSStrategy(string mobileNumber){
        this->mobileNumber = mobileNumber;
    }
    
    void sendNotification(string content) override{
        cout<<"sending SMS notification to " << mobileNumber << endl;
    }

};

class PopUpStrategy : public INotificationStrategy{
    public:
    void sendNotification(string content) override{
        cout<<"Showing pop-up notification: " << content << endl;
    }
};

class NotificationEngine : public IObserver{
private:
    NotificationObservable * notificationObservable;
    vector<INotificationStrategy*> notificationStrategies;
public:
    NotificationEngine(NotificationObservable* observable){
        this->notificationObservable = observable;
    }
    
    void addNotifcationStrategy(INotificationStrategy* ns){
        this->notificationStrategies.push_back(ns);
    }

    //can have removenotification strategy method
    void update(){
        string notificationContent = notificationObservable->getNotificationContent();
        for(const auto notificationStragety: notificationStrategies){
            notificationStragety->sendNotification(notificationContent);
        }
    }
};

//notificatoin services
//any client code will intereact with this service t

//singleton classs
class NotificationService{
private:
    NotificationObservable* observable;
    static NotificationService* instance;
    vector<INotification*> notification;

    NotificationService(){
        //private constructor
        observable = new NotificationObservable();
    }

public:
    static NotificationService* getInstance(){
        if(instance == nullptr){
            instance = new NotificationService();
        }
        return instance;
    }

    //expose the observable so observers can attach 
    NotificationObservable* getObservable(){
        return observable;
    }

    //create a new notification and notifies observers
    void sendNotification(INotification* notif){
        notification.push_back(notif);
        observable->setNotificatoin(notif);
        
    }

    ~NotificationService(){
        delete observable;
    }
};

NotificationService * NotificationService::instance = nullptr;

int main() {
    //create notification service
    NotificationService* notificationService = NotificationService::getInstance();

    // get ovbservalbe 
    NotificationObservable* notificationObservable = notificationService->getObservable();

    //create a logger observer
    Logger* logger = new Logger(notificationObservable);

    //creawte a notifcatoin engine observer
    NotificationEngine* notificationEngine =new NotificationEngine(notificationObservable);
    
    notificationEngine->addNotifcationStrategy(new EmailStrategy("nahraf.xd@gmail.com"));
    notificationEngine->addNotifcationStrategy(new SMSStrategy("+1234567890"));
    notificationEngine->addNotifcationStrategy(new PopUpStrategy());

    //attach observerrs
    notificationObservable->addObserver(logger);
    notificationObservable->addObserver(notificationEngine);

    //create a notification with decorators
    INotification* notification = new SimpleNotifcation("Your order has been shipped!");
    notification = new TimeStampDecorator(notification);
    notification = new SignatureDecorator(notification, "Cusotmer care");

    //send notification 
    notificationService->sendNotification(notification);    
    
    //clean up
    delete logger;
    delete notificationEngine;


    return 0;
}