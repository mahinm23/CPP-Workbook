// Reference solution for ../Ex8/08_final_challenge.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Order {
public:
    Order(std::string symbol, double price, int quantity)
        : symbol_(symbol), price_(price), quantity_(quantity) {}

    std::string getSymbol() const { return symbol_; }
    double getPrice() const { return price_; }
    int getQuantity() const { return quantity_; }

    virtual void print() const {
        std::cout << symbol_ << " x" << quantity_ << " @ " << price_ << "\n";
    }

    virtual ~Order() {}

private:
    std::string symbol_;
    double price_;
    int quantity_;
};

class BuyOrder : public Order {
public:
    BuyOrder(std::string symbol, double price, int quantity)
        : Order(symbol, price, quantity) {}

    void print() const override {
        std::cout << "BUY  " << getSymbol() << " x" << getQuantity() << " @ " << getPrice() << "\n";
    }
};

class SellOrder : public Order {
public:
    SellOrder(std::string symbol, double price, int quantity)
        : Order(symbol, price, quantity) {}

    void print() const override {
        std::cout << "SELL " << getSymbol() << " x" << getQuantity() << " @ " << getPrice() << "\n";
    }
};

bool orderLess(const Order* a, const Order* b) {
    return a->getPrice() < b->getPrice();
}

std::ostream& operator<<(std::ostream& os, const Order& o) {
    os << o.getSymbol() << " @ " << o.getPrice();
    return os;
}

// Point 4 (rule of three): Order/BuyOrder/SellOrder hold only value members (string, double,
// int) - no raw pointer or manually-managed resource. The compiler-generated copy/move members
// already do the right thing here, so no custom destructor/copy/move is needed. That would only
// change if a member started owning a resource manually (e.g. a raw pointer from `new`) -
// without matching copy/move members, two copies would share the same pointer and either
// double-free it or leave one dangling once the other is destroyed.

int main() {
    std::vector<Order*> orders;
    orders.push_back(new BuyOrder("AAPL", 150.5, 100));
    orders.push_back(new SellOrder("AAPL", 149.75, 50));
    orders.push_back(new BuyOrder("TSLA", 700.0, 10));

    std::sort(orders.begin(), orders.end(), orderLess);

    for (Order* o : orders) {
        o->print();   // polymorphic dispatch - BUY/SELL printed per actual object type
    }

    for (Order* o : orders) {
        delete o;
    }

    return 0;
}
