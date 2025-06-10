#include <iostream>
using namespace std;

class WalkableRobot{
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};
//concrete strategies for walk 
class Normalwalk : public WalkableRobot {   
public:
    void walk() override {
        cout << "Walking normally." << endl;
    }
};  

class Nowalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Not walking." << endl;
    }
};

class TalkableRobot{
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

//concrete strategies for talk
class NormalTalk : public TalkableRobot {
public:
    void talk() override {
        cout << "Talking normally." << endl;
    }
};
class Notalk : public TalkableRobot {
public:
    void talk() override {
        cout << "Not talking." << endl;
    }
};

class FlyableRobot{
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
}; 

class NormalFly : public FlyableRobot {
public:
    void fly() override {
        cout << "Flying normally." << endl;
    }
};
class Nofly : public FlyableRobot {
public:
    void fly() override {
        cout << "Not flying." << endl;
    }
};

//robot base class

class Robot{
protected:
    WalkableRobot * walkBehavior;
    TalkableRobot * talkBehavior;
    FlyableRobot * flyBehavior;
public:
    Robot(WalkableRobot *w, TalkableRobot *t, FlyableRobot*f){
        this->walkBehavior = w;
        this->talkBehavior = t; 
        this->flyBehavior = f;
    }

    void walk(){
        walkBehavior->walk();
    }
    void talk(){
        talkBehavior->talk();
    }
    void fly(){
        flyBehavior->fly();
    }

    //abstract methods for projection 
    virtual void projection() = 0;
};

class CompanionRobot: public Robot{
    public:
    CompanionRobot(WalkableRobot*w, TalkableRobot*r, FlyableRobot*f)
        : Robot(w, r, f) {}
    void projection() override {
        cout<<"displaying frendly companions features...." << endl;
}
};

class WorkerRobot: public Robot{
    public:
    WorkerRobot(WalkableRobot*w, TalkableRobot*r, FlyableRobot*f)
        : Robot(w, r, f) {}
    void projection() override{
        cout<<"displaying worker efficiency stats..."<<endl;
    }
};

int main() {

    Robot *robot1 = new CompanionRobot(new Normalwalk(), new NormalTalk(), new Nofly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout<<"------------------------" << endl;

    Robot *robot2 = new WorkerRobot(new Nowalk(), new Notalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();
    
    return 0;
}