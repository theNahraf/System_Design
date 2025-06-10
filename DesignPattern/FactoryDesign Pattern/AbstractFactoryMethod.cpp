#include <iostream>
using namespace std;
class Burger {
public:
    virtual void prepare() =0;
};
class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Burger" << endl;
    }
};
class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Burger" << endl;
    }
};
class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Burger" << endl;
    }
};

class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Wheat Burger" << endl;
    }
};
class StandardWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Wheat Burger" << endl;
    }
};
class PremiumWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Wheat Burger" << endl;
    }
};

class GarlicBread {
public:
    virtual void prepare() =0;
};

class BasicGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Basic Garlic Bread" << endl;
    }
};
class StandardGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Standard Garlic Bread" << endl;
    }
};
class PremiumGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Premium Garlic Bread" << endl;
    }
};
class BasicWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Basic Wheat Garlic Bread" << endl;
    }
};
class StandardWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Standard Wheat Garlic Bread" << endl;
    }
};
class PremiumWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Premium Wheat Garlic Bread" << endl;
    }
};

class Mealfactory{

public:
    virtual Burger* createBurger(string & type) = 0;
    virtual GarlicBread* createGarlicBread(string & type) = 0;
};

class SinghBurger : public Mealfactory{
public:
    Burger* createBurger(string & type) override {
        if (type == "Basic") {
            return new BasicBurger();
        } else if (type == "Standard") {
            return new StandardBurger();
        } else if (type == "Premium") {
            return new PremiumBurger();
        } else {
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string & type) override {
        if (type == "Basic") {
            return new BasicGarlicBread();
        } else if (type == "Standard") {
            return new StandardGarlicBread();
        } else if (type == "Premium") {
            return new PremiumGarlicBread();
        } else {
            return nullptr;
        }
    }
};

int main() {
    string burgerType = "Premium";
    string garlicBreadType = "Standard";
    Mealfactory* factory = new SinghBurger();
    Burger * burger = factory->createBurger(burgerType);
    GarlicBread * garlicBread = factory->createGarlicBread(garlicBreadType);    

    burger->prepare();
    garlicBread->prepare();

    

    return 0;
}