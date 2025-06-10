#include <iostream>
using namespace std;

class Parent{
public:
    virtual void print(string msg){
        cout << "Parent: " << msg << endl;
    }
};

class child : public Parent{
public:
    void print(string msg) override{
        cout << "Child: " << msg << endl;
    }

};

class Client { 
private:
    Parent *p;

    public:
Client(Parent *p){
    this->p = p;
}
    void printmst(){
        p->print("Hello");
    }
};

int main() {
    Parent *p =  new Parent();
    Parent *c  = new child();


    //client * client = new client(parent)

    Client * client =  new Client(p);
    Client * client1 =  new Client(c);
    client->printmst();
    client1->printmst();


    return 0;
}