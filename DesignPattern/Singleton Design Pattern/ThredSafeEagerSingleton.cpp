#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    // Private constructor to prevent instantiation
    Singleton() {
        cout << "Singleton constructor called" << endl;
    }
public:
    static Singleton *getInstance(){
        return instance;
    }
};   

// Initialize the static instance pointer

// problem  , object create krne se pehle hi instance create ho jayega

Singleton* Singleton::instance = new Singleton();

int main() {
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    if (s1 == s2) {
        cout << "Both instances are the same." << endl;
    } else {
        cout << "Instances are different." << endl;
    }
    return 0;
}