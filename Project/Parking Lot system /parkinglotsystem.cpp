#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <mutex>
#include <ctime>
#include <algorithm>
using namespace std;

// ================= ENUMS =================
enum class VehicleType { BIKE, CAR, TRUCK };

// ================= VEHICLE STRATEGY =================
class VehicleStrategy {
public:
    virtual VehicleType getType() = 0;
    virtual ~VehicleStrategy() {}
};

class CarStrategy : public VehicleStrategy {
public:
    VehicleType getType() override { return VehicleType::CAR; }
};

class BikeStrategy : public VehicleStrategy {
public:
    VehicleType getType() override { return VehicleType::BIKE; }
};

// ================= VEHICLE =================
class Vehicle {
    string license;
    VehicleStrategy* strategy;

public:
    Vehicle(string lic, VehicleStrategy* s) : license(lic), strategy(s) {}

    VehicleType getType() {
        return strategy->getType();
    }

    string getLicense() { return license; }
};

// ================= PARKING SPOT =================
class ParkingSpot {
    int id;
    VehicleType type;
    bool isFree;
    Vehicle* vehicle;

public:
    ParkingSpot(int id, VehicleType type)
        : id(id), type(type), isFree(true), vehicle(nullptr) {}

    bool canFit(VehicleType vtype) {
        return isFree && vtype == type;
    }

    void park(Vehicle* v) {
        vehicle = v;
        isFree = false;
    }

    void unpark() {
        vehicle = nullptr;
        isFree = true;
    }

    int getId() { return id; }
    VehicleType getType() { return type; }
    bool free() { return isFree; }
};

// ================= PARKING TICKET =================
class ParkingTicket {
    int id;
    Vehicle* vehicle;
    ParkingSpot* spot;
    time_t entryTime;

public:
    ParkingTicket(int id, Vehicle* v, ParkingSpot* s)
        : id(id), vehicle(v), spot(s) {
        entryTime = time(nullptr);
    }

    int getId() { return id; }
    Vehicle* getVehicle() { return vehicle; }
    ParkingSpot* getSpot() { return spot; }

    int getDurationHours() {
        time_t now = time(nullptr);
        return max(1, (int)difftime(now, entryTime) / 3600);
    }
};

// ================= PRICING STRATEGY =================
class PricingStrategy {
public:
    virtual double calculate(ParkingTicket* ticket) = 0;
    virtual ~PricingStrategy() {}
};

// simple dynamic pricing
class DynamicPricing : public PricingStrategy {
public:
    double calculate(ParkingTicket* ticket) override {
        int hours = ticket->getDurationHours();
        double base = hours * 20;

        // vehicle multiplier
        if (ticket->getVehicle()->getType() == VehicleType::TRUCK)
            base *= 2;
    
        // peak hour multiplier (simulate)
        time_t now = time(nullptr);
int hour = localtime(&now)->tm_hour;
        if (hour >= 18 && hour <= 22)
            base *= 1.5;

        return base;
    }
};

// ================= PAYMENT STRATEGY =================
class PaymentStrategy {
public:
    virtual bool pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};

class UPIPayment : public PaymentStrategy {
public:
    bool pay(double amount) override {
        cout << "Paid via UPI: " << amount << endl;
        return true;
    }
};

class CashPayment : public PaymentStrategy {
public:
    bool pay(double amount) override {
        cout << "Paid via Cash: " << amount << endl;
        return true;
    }
};

// ================= PAYMENT =================
class Payment {
    double amount;
    PaymentStrategy* strategy;

public:
    Payment(double amt, PaymentStrategy* s)
        : amount(amt), strategy(s) {}

    bool process() {
        return strategy->pay(amount);
    }
};

// ================= PARKING FLOOR =================
class ParkingFloor {
    unordered_map<int, ParkingSpot*> spots;
    unordered_map<VehicleType, set<int>> freeSpots;
    mutex mtx;

public:
    void addSpot(ParkingSpot* spot) {
        spots[spot->getId()] = spot;
        freeSpots[spot->getType()].insert(spot->getId());
    }

    ParkingSpot* park(Vehicle* v) {
        lock_guard<mutex> lock(mtx);

        auto& s = freeSpots[v->getType()];
        if (s.empty()) return nullptr;

        int id = *s.begin();
        s.erase(id);

        spots[id]->park(v);
        return spots[id];
    }

    void unpark(ParkingSpot* spot) {
        lock_guard<mutex> lock(mtx);

        spot->unpark();
        freeSpots[spot->getType()].insert(spot->getId());
    }
};

// ================= PARKING LOT =================
class ParkingLot {
    ParkingFloor floor;
    unordered_map<int, ParkingTicket*> tickets;
    int ticketCounter = 0;
    PricingStrategy* pricingStrategy;
    mutex mtx;

public:
    ParkingLot(PricingStrategy* ps) : pricingStrategy(ps) {}

    void addSpot(ParkingSpot* spot) {
        floor.addSpot(spot);
    }

    int parkVehicle(Vehicle* v) {
        lock_guard<mutex> lock(mtx);

        ParkingSpot* spot = floor.park(v);
        if (!spot) {
            cout << "No spot available\n";
            return -1;
        }

        int ticketId = ++ticketCounter;
        tickets[ticketId] = new ParkingTicket(ticketId, v, spot);

        cout << "Vehicle parked. Ticket: " << ticketId << endl;
        return ticketId;
    }

    void unparkVehicle(int ticketId, PaymentStrategy* paymentStrategy) {
        lock_guard<mutex> lock(mtx);

        if (!tickets.count(ticketId)) return;

        ParkingTicket* ticket = tickets[ticketId];

        // STEP 1: pricing
        double amount = pricingStrategy->calculate(ticket);

        // STEP 2: payment
        Payment payment(amount, paymentStrategy);
        if (!payment.process()) {
            cout << "Payment failed\n";
            return;
        }

        // STEP 3: free spot
        floor.unpark(ticket->getSpot());

        cout << "Vehicle exited\n";
        tickets.erase(ticketId);
    }
};

// ================= MAIN =================
int main() {
    PricingStrategy* pricing = new DynamicPricing();
    ParkingLot lot(pricing);

    // add spots
    lot.addSpot(new ParkingSpot(1, VehicleType::CAR));
    lot.addSpot(new ParkingSpot(2, VehicleType::BIKE));

    // vehicles
    Vehicle* car = new Vehicle("DL01", new CarStrategy());
    Vehicle* bike = new Vehicle("DL11", new BikeStrategy());

    // park
    int ticket = lot.parkVehicle(car);
    int tik1=  lot.parkVehicle(bike);

    // simulate exit
    PaymentStrategy* payment = new UPIPayment();
    lot.unparkVehicle(ticket, payment);
    lot.unparkVehicle(tik1, payment);

    return 0;
}