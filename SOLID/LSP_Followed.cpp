#include <iostream>
#include <vector>
using namespace std;

class DepositOnlyaccount{
public:
    virtual void deposit(double amount) = 0;
};
class WithdrawableAccount : public DepositOnlyaccount{
public:
    virtual void withdraw(double amount) = 0;
};

class Savingaccount : public WithdrawableAccount{
    private:
    double balance; 
public:
    Savingaccount()
{
    balance = 0;
}

void deposit(double amount){
    balance += amount;
    cout << "Deposited: " << amount << endl;    
}

void withdraw(double amount) {
    if(balance >= amount) { 
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
        cout << "New balance: " << balance << endl;
    }
    else {
        cout << "Insufficient funds" << endl;
    }
}

};


class Currentaccount : public WithdrawableAccount{
private:
    double balance; 
public:
    Currentaccount()
{
    balance = 0;
}

void deposit(double amount){
    balance += amount;
    cout << "Deposited: " << amount << endl;    
}

void withdraw(double amount) {
    if(balance >= amount) { 
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
        cout << "New balance: " << balance << endl;
    }
    else {
        cout << "Insufficient funds" << endl;
    }
}

};

class FixedDepositaccount  : public DepositOnlyaccount{
private:
    double balance;

public: 
    FixedDepositaccount(){
        balance = 0;
    }

    void deposit(double amount){
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }
};

class BankClient{
private:
    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<DepositOnlyaccount*> depositOnlyAccounts;
public:

    BankClient(vector<WithdrawableAccount*> withdrawableAccounts, vector<DepositOnlyaccount*> depositOnlyAccounts){
        this->withdrawableAccounts = withdrawableAccounts;
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void processTransaction(){
        for(WithdrawableAccount * acc : withdrawableAccounts){
            acc->deposit(1000); //all acounts allow deposit 
            acc->withdraw(500); //only withdrawable accounts allow withdraw
        }
        for(DepositOnlyaccount * acc : depositOnlyAccounts){
            acc->deposit(5000);
        }

    }
   
};

int main() {

    vector<WithdrawableAccount*> withdrawableAccounts;

    withdrawableAccounts.push_back(new Savingaccount());
    withdrawableAccounts.push_back(new Currentaccount());   

    vector<DepositOnlyaccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedDepositaccount());

    BankClient* client = new BankClient(withdrawableAccounts, depositOnlyAccounts);

    client->processTransaction();


    return 0;
}