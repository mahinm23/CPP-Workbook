// Reference solution for ../06_polymorphism.cpp

#include <iostream>
#include <string>
#include <vector>

class Order {
public:
    Order(std::string symbol, int quantity) : symbol_(symbol), quantity_(quantity) {}

    virtual void print() {
        std::cout << symbol_ << " x" << quantity_ << "\n";
    }

    virtual ~Order() {
        std::cout << "Order destroyed (" << symbol_ << ")\n";
    }

protected:
    std::string symbol_;
    int quantity_;
};

class LimitOrder : public Order {
public:
    LimitOrder(std::string symbol, int quantity, double price)
        : Order(symbol, quantity), price_(price) {}

    void print() override {
        std::cout << symbol_ << " x" << quantity_ << " @ " << price_ << "\n";
    }

private:
    double price_;
};

class MarketOrder : public Order {
public:
    MarketOrder(std::string symbol, int quantity) : Order(symbol, quantity) {}

    void print() override {
        std::cout << symbol_ << " x" << quantity_ << " (market)\n";
    }
};

int main() {
    std::vector<Order*> orders;
    orders.push_back(new LimitOrder("AAPL", 100, 150.5));
    orders.push_back(new MarketOrder("TSLA", 50));

    for (Order* o : orders) {
        o->print();   // dispatches to the actual object's override, not Order's
    }

    for (Order* o : orders) {
        delete o;      // virtual destructor ensures the derived part is cleaned up too
    }

    return 0;
}
