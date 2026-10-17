// Reference solution for ../05_inheritance.cpp

#include <iostream>
#include <string>

class Order {
public:
    Order(std::string symbol, int quantity) : symbol_(symbol), quantity_(quantity) {}

    void print() {
        std::cout << symbol_ << " x" << quantity_ << "\n";
    }

protected:
    std::string symbol_;
    int quantity_;
};

class LimitOrder : public Order {
public:
    LimitOrder(std::string symbol, int quantity, double price)
        : Order(symbol, quantity), price_(price) {}

    void print() {
        std::cout << symbol_ << " x" << quantity_ << " @ " << price_ << "\n";
    }

private:
    double price_;
};

class MarketOrder : public Order {
public:
    MarketOrder(std::string symbol, int quantity) : Order(symbol, quantity) {}
    // no new members, no new print() - reuses Order's as-is
};

int main() {
    LimitOrder lo("AAPL", 100, 150.5);
    MarketOrder mo("TSLA", 50);

    lo.print();
    mo.print();

    return 0;
}
