#include <iostream>
using namespace std;

class Command{
public:
    virtual void execute() =0;
    virtual void undo() =0;
    virtual ~Command() {}
};

//recerver class
class Light {
public:
    void on(){
        cout << "Light is ON" << endl;
    }
    void off(){
        cout << "Light is OFF" << endl;
    }
};
class Fan{
public:
    void on(){
        cout << "Fan is ON" << endl;
    }
    void off(){
        cout << "Fan is OFF" << endl;
    }
};

//cncreate command classes
class LightCommand : public Command{
private:
    Light* light;
public:
    LightCommand(Light*l){
        light = l;
    };
    
    void execute() override{
        light->on();
    }
    void undo() override {
        light->off();
    }
};

class FanCommand : public Command{
private:
    Fan* fan;
public:
    FanCommand(Fan* f){
        fan = f;
    }
    
    void execute() override {
        fan->on();
    }
    
    void undo() override {
        fan->off();
    }
};

//invoker : Remote controler with static 2d array of 6 button(3 row, 2 cols)

class RemoteController{
private:
    static const int numButtons = 4;
    Command* buttons[numButtons];
    bool buttonPressed[numButtons];

public:
    RemoteController(){
        for(int i = 0; i < numButtons; i++) {
            buttons[i] = nullptr;
            buttonPressed[i] = false;
        }
    }
    void setCommand(int ind, Command* cmd){
        if(ind>=0 && ind < numButtons){
            if(buttons[ind]!=nullptr){
                delete buttons[ind]; // Clean up previous command
            }
            buttons[ind] = cmd;
            buttonPressed[ind] = false; // Reset button state
        }
        else{
            cout << "Invalid button index: " << ind << endl;
        }
    }

    void pressButton(int ind){
        if(ind>=0 && ind<numButtons && buttons[ind]!=nullptr){
            if(buttonPressed[ind]==false){
                buttons[ind]->execute();
            }
            else{
                buttons[ind]->undo();
            }
            buttonPressed[ind] = !buttonPressed[ind]; // Toggle button state
        }
        else{
            cout<<"no command set for this button : "<< ind << endl;
        }
    }


    ~RemoteController() {
        for(int i = 0; i < numButtons; i++) {
            if(buttons[i] != nullptr) {
                delete buttons[i]; // Clean up commands
            }
        }
    }

};


int main() {

    Light * livingRoomLight = new Light();
    Fan * cellingFan = new Fan();

    RemoteController * remote = new RemoteController();

    remote->setCommand(0, new LightCommand(livingRoomLight));
    remote->setCommand(1, new FanCommand(cellingFan));  

    //simultae button press (toogle behaviours)

    cout<<"----Toggling light Button 0----"<<endl;
    remote->pressButton(0); // Turn on light
    remote->pressButton(0); // Turn off light


    cout<<"----Toggling Fan Button 1----"<<endl;
    remote->pressButton(1); // Turn on fan
    remote->pressButton(1); // Turn off fan

    //press unassigned button to show defalut mesasge
    cout<<"----Pressing unassigned button 2----"<<endl;
    remote->pressButton(2); // No command set for this button
    

    //clean up
    delete remote;
    delete livingRoomLight;
    delete cellingFan;
    cout << "Remote control simulation completed." << endl;
    return 0;   
}