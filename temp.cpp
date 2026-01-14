#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

class Singleton{
private:
    static Singleton* Instance;
    Singleton(){
        cout<<"constructor is called , new object created"<<endl;
    }
public:
   static Singleton* getInstance(){
        if(Instance == nullptr){
            Instance = new Singleton();
        }
        return Instance;
    }

};

Singleton* Singleton::Instance = nullptr;
 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    
    cout<<(s1==s2)<<endl;
    

    return 0;
}