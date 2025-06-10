#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


// Observer Design Pattern
class ISubscriber{
public:
    virtual void update() =0;
    virtual ~ISubscriber(){}
};

class IChannel{
    public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notify() = 0;
    virtual ~IChannel(){}
};

//concrete implementation of IChannel
class Channel : public IChannel{
private:
    vector<ISubscriber*> subscribers;
    string name;
    string latestVideo;
public:
    Channel(const string &name){
        this->name = name;
    }
    void subscribe(ISubscriber* subscriber) override{
        if(find(subscribers.begin(), subscribers.end(), subscriber)== subscribers.end()){
            subscribers.push_back(subscriber);
            cout <<" subscribed to " << name << endl;
        }
    }

    void uploadVideo(const string &title){
        latestVideo = title;
        cout << "New video uploaded on " << name << ": " << latestVideo << endl;
        notify();
    }


    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if(it != subscribers.end()){
            subscribers.erase(it);
            cout <<" unsubscribed from " << name << endl;
        }
    }

    void notify() override{
        for(auto subs: subscribers){
            subs->update();
        }
    }

    string getVideo(){
        return "New video uploaded on : " + latestVideo;
    }

};

class Subscriber : public ISubscriber{
private:
    string name;
    Channel *channel;
public:
    Subscriber(const string &name, Channel *channel){
        this->name = name;
        this->channel = channel;
    }

    void update() override{
        cout << "hey" << name << ", " << channel->getVideo() << endl;
    }

};


int main() {

    Channel * channel = new Channel("Urrafx");
    Subscriber * sub1 =new Subscriber("John", channel);
    Subscriber * sub2 =new Subscriber("tarun", channel);


    //both subscribers subscribe to the channel
    channel->subscribe(sub1);
    channel->subscribe(sub2);

    //channel uploads a new video
    channel->uploadVideo("Oberserver Design Pattern");

    //one subscriber unsubscribes
    channel->unsubscribe(sub1);

    //channel uploads another video
    channel->uploadVideo("namaste dsa video final");
    

    return 0;
}