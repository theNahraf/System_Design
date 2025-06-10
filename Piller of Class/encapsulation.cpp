#include <iostream>
using namespace std;

class SportsCar{
    private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    //introduction to new variable 
    string tyreCompany;

public:
    SportsCar(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;  
        tyreCompany = "MRF";
    }

    int getSpeed(){
        return currentSpeed;
    }

    string getTyreCompany(){
        return tyreCompany;
    }

    void setTyreCompany(string company){
        this->tyreCompany = company;
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
        cout << brand << " " << model << " :  accelerated to " << currentSpeed << " km/h" << endl;
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
        cout << brand << " " << model << " :  engine stopped" << endl;
    }

    ~SportsCar(){
        cout << "Destructor called for " << brand << " " << model << endl;
    }


};

int main() {

    SportsCar* mysportsCar  = new SportsCar("Ferrari", "F8");
    mysportsCar->startEngine();
    mysportsCar->shiftGear(3);
    mysportsCar->accelerate();
    // mysportsCar->brake();
    mysportsCar->stopEngine();
    mysportsCar->setTyreCompany("Bridgestone");
    cout << "Tyre company: " << mysportsCar->getTyreCompany() << endl;
    cout << "Current speed: " << mysportsCar->getSpeed() << " km/h" << endl;
    delete mysportsCar; // Destructor will be called here

    
    return 0;
}