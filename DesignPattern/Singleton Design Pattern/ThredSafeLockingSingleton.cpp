#include <iostream>
#include <mutex>

using namespace std;

//static method class ko belong krta hai objext ko nhi
// isliye static method ko call krne ke liye object ki zarurat nhi hoti

class Singleton{
private:
    static Singleton* instance;
    static mutex mtx;
    // static Singleton* instance = nullptr ;
     Singleton(){
        cout<<"singleton constructor called"<<endl;
    }

public:
    //multiple threds se ek se jayda objext creat ho jayeaga without mutex

    static Singleton* getInstance(){
        if(instance == nullptr) {
            //lock the mutex to prevent multiple threads from creating multiple instances
            lock_guard<mutex> lock(mtx);
            //check again to ensure that another thread hasn't created an instance while this thread was waiting for the lock
            if(instance == nullptr) //double check locking
                 instance = new Singleton();
        }
        return instance;
    }
};

//c++ me instance ko initialize krne ka best practice hai ki usko class ke bahar initialize kiya jaye
//java me instance ko class ke andar hi initialize krte hain
Singleton* Singleton::instance = nullptr; 
mutex Singleton::mtx;
int main() {

    Singleton * s1 = Singleton::getInstance();
    Singleton * s2 = Singleton::getInstance();
    
    return 0;
}