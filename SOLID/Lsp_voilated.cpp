#include <iostream>
using namespace std;
#include <vector>
#include<typeinfo>

class Account {
public:
    virtual void deposit(double amount) =0;
    virtual void withdraw(double amount) = 0;
};


class SavingsAccount: public Account {
private:
    double balance;

public:
    SavingsAccount(){
        balance = 0;
    }

    void deposit(double amount){
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }
    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
            cout << "New balance: " << balance << endl;
        }
        else{
            cout << "Insufficient funds" << endl;
        }
    }
};


class Currentaccount: public Account {
private:
    double balance;

public:
    Currentaccount(){
        balance = 0;
    }

    void deposit(double amount){
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }
    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
            cout << "New balance: " << balance << endl;
        }
        else{
            cout << "Insufficient funds" << endl;
        }
    }
};

class FixedDepositAccount: public Account {
private:
    double balance;

public:
    FixedDepositAccount(){
        balance = 0;
    }
    
    void deposit(double amount){
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount){
        throw logic_error("Cannot withdraw from Fixed Deposit Account");
    }

};

class bankclient{
private:
    vector<Account*> accounts;
public:
    bankclient(vector<Account*> accounts){
        this->accounts  =  accounts;
    }

    void processTransaction(){
        for(Account * acc : accounts){
            acc->deposit(1000); //all acounts allow deposit 

            //checking accont type 
            if(typeid(*acc) == typeid(FixedDepositAccount)){
                cout << "skipping withdraw for Fixed Deposit Account" << endl;
            }
            else{

                try{
                    acc->withdraw(500);
                }
                catch(const logic_error& e){
                    cout<<"exception : " << e.what() << endl;
                }
            }
        }
    }
};



int main() {

    vector<Account *> accounts;
    accounts.push_back(new SavingsAccount());
    accounts.push_back(new Currentaccount());
    accounts.push_back(new FixedDepositAccount());

    bankclient* Client =  new bankclient(accounts);

    //throw exceptoin whe withdraw from fixed deposit account 
    Client->processTransaction();

    return 0;
}