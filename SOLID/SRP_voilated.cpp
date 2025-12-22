#include <iostream>
#include <vector>
using namespace std;

class Product {
public:
    string name;
    double price;
  Product(string name, double price){
    this->name = name;
    this->price = price;
  }
};

class ShoppingCart{
private:
    vector<Product> products;

public:
    void addProduct(Product p){
        products.push_back(p);
    }

    const vector<Product >& getProducts(){
        return products;
    }

    //calculate total price
    double calculateTotalPrice(){
        double total = 0;
        for(auto p : products){
            total += p.price;
        }
        return total;
    }
    
};

//2. shoping cart printer : only reponsible for printing invoices

class ShoppingCartPrinter{
private:
    ShoppingCart *cart;
public:
    ShoppingCartPrinter(ShoppingCart * cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout<<"shopping cart invoice"<<endl;
        cout<<"-------------------"<<endl;
        for(auto p : cart->getProducts()){
            cout<<p.name<<" : "<<p.price<<endl;
        }
        cout<< "Total  : " << cart->calculateTotalPrice() << endl;

    }

};

// 3. shoppingcartstorage : only responsible for storing shopping cart

class shoppingCartStorage{
    private:
        ShoppingCart * cart;  
public:
    shoppingCartStorage(ShoppingCart * cart){
        this->cart = cart;
    }


    void savetoDB(){
        cout<<"shopping cart save to database"<<endl;
    }

};

//abstract class for solid O;



class dbpersistance{
   private:
    ShoppingCart * cart;
    public:
    virtual void save(ShoppingCart *cart) = 0; //pure virtual function
    
};

class SQLPersistance : public dbpersistance{
    public:
        void save(ShoppingCart *cart){
            cout<<"saving to sql database"<<endl;
        }
};

class MongoPersistance: public dbpersistance{
    public:
    void save(ShoppingCart *cart){
        cout<<"saving to mongo database"<<endl;
    }
};

class FilePersistance: public dbpersistance{
    public:
    void save(ShoppingCart *cart){
        cout<<"saving to file"<<endl;
    }
};

int main() {
    ShoppingCart * cart = new ShoppingCart();

    cart->addProduct( Product("apple", 1.5));
    cart->addProduct( Product("banana", 2.5));

    ShoppingCartPrinter * printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    dbpersistance * db = new SQLPersistance();
dbpersistance * mongo  = new MongoPersistance();
    dbpersistance * file = new FilePersistance();

    db->save(cart); 
    mongo->save(cart);
    file->save(cart);
    

    // shoppingCartStorage * db= new shoppingCartStorage(cart);
    // db->savetoDB(); 

    return 0;
}



