#include <iostream>
using namespace std;

class Burger{
public:
    virtual void prepare() = 0;
    virtual ~Burger(){} // Virtual destructor for proper cleanup
};

class BasicBurger: public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Burger" << endl;
    }
};
class StandardBurger: public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Burger" << endl;
    }
};
class PremiumBurger: public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Burger" << endl;
    }
};

class BasicWheatBurger: public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Wheat Burger" << endl;
    }
};
class StandardWheatBurger: public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Wheat Burger" << endl;
    }
};
class PremiumWheatBurger: public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Wheat Burger" << endl;
    }
};

class BurgerFactory{
public:
    virtual Burger* createBurger(string &type) = 0;
};

class SinghBurger: public BurgerFactory {
public:
    Burger* createBurger(string &type) override{
        if (type == "Basic") {
            return new BasicBurger();
        } else if (type == "Standard") {
            return new StandardBurger();
        } else if (type == "Premium") {
            return new PremiumBurger();
        } else {
            cout << "Invalid burger type" << endl;
            return nullptr; // or throw an exception
        }
    }
};
class KingBurger: public BurgerFactory {
public:
    Burger* createBurger(string &type) override{
        if (type == "Basic") {
            return new BasicWheatBurger();
        } else if (type == "Standard") {
            return new StandardWheatBurger();
        } else if (type == "Premium") {
            return new PremiumWheatBurger();
        } else {
            cout << "Invalid burger type" << endl;
            return nullptr; // or throw an exception
        }
    }
};

int main() {
    string type = "Standard";
    BurgerFactory* myBurgerFactory = new SinghBurger();
    Burger *burger = myBurgerFactory->createBurger(type);
    
    burger->prepare();

    return 0;
}