#include <iostream>
using namespace std;

class base {
public:
    base(){
        cout << "base constructor called" << endl;
    }
    base(int x){
        cout << "base constructor with parameter called: " << x << endl;
    }
};
int main() {
    base b1; // Calls default constructor
    base b2(10); // Calls parameterized constructor
    
    return 0;
}