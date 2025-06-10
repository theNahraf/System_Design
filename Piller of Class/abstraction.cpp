#include <iostream>
using namespace std;

class Car{
    public: 
    virtual void startEngine() =0;
    virtual void shiftGear(int gear) = 0;
    virtual void stopEngine() =0;
    virtual void accelerate() =0;
    virtual void brake() =0;

    //destructor
    virtual ~Car(){
        cout << "Car destructor called" << endl;
    }

};


class SportsCar : public Car{
    public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;


public:
    SportsCar(string b, string m ){
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
        this->currentGear = 0;  
    }

    void startEngine(){
        isEngineOn = true;
        cout << brand << " " << model << " :  engine start with a roar " << endl; 
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout << "Engine is off. Cannot shift gear." << endl;
            return;
        }
        if(gear < 1 || gear > 6){
            cout << "Invalid gear. Please select a gear between 1 and 6." << endl;
            return;
        }
        currentGear = gear; 
        cout << brand << " " << model << " :  gear shifted to " << currentGear << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << "Engine is off. Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 10;
        cout << brand << " " << model << " :  accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake(){
        currentSpeed  -=20;
        if(currentSpeed < 0){
            currentSpeed = 0;
        }
        cout << brand << " " << model << " :  braking to " << currentSpeed << " km/h" << endl;
    }

    void stopEngine(){
        if(!isEngineOn){
            cout << "Engine is already off." << endl;
            return;
        }
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << brand << " " << model << " :  engine stopped" << endl;
    }

};

int main() {

    Car *mycar = new SportsCar("Ferrari", "488");
    mycar->startEngine();
    mycar->shiftGear(3);
    mycar->accelerate();
    mycar->brake();
    mycar->stopEngine();
    delete mycar;
    return 0;
}