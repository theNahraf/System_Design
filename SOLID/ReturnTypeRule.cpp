#include <iostream>
using namespace std;


//same for exception rule 
class Organism{
    //some common organism methods
};
class Animal : public Organism {
//some common animal methods
};

class Dog: public Animal { 
    //aditional dog methods
};

class Parent {
public:
    virtual Animal* getAnimal(){
        cout << "Parent: getAnimal" << endl;
        return new Animal();
    }
};

class Child: public Parent{
public:
    Dog* getAnimal() override{
        cout << "Child: getAnimal" << endl;
        return new Dog();
    }
};


class Client{
private:
    Parent *p;

public:
    Client(Parent *p){
        this->p = p;
    }

    void takeAnimal(){
        p->getAnimal();
    }
};
int main() {

    Parent *p = new Parent();
    Child *c =  new Child();
    Client * client1 = new Client(p);
    Client * client =  new Client(c);
    client->takeAnimal();
    client1->takeAnimal();


    return 0;
}