// Reference solution for ../Ex3/03_encapsulation.cpp

#include <iostream>
#include <string>

class Order {
public:
    Order(std::string symbol, double price, int quantity)
        : symbol_(symbol), price_(price), quantity_(quantity) {}

    std::string getSymbol() const { return symbol_; }
    double getPrice() const { return price_; }
    int getQuantity() const { return quantity_; }

    void setQuantity(int q) {
        if (q < 0) {
            std::cout << "Error: quantity cannot be negative (" << q << ")\n";
            return;
        }
        quantity_ = q;
    }

private:
    std::string symbol_;
    double price_;
    int quantity_;
};

int main() {
    Order o("AAPL", 150.5, 100);

    o.setQuantity(-10);
    std::cout << o.getSymbol() << " qty after -10 attempt: " << o.getQuantity() << "\n";

    o.setQuantity(50);
    std::cout << o.getSymbol() << " qty after setting 50: " << o.getQuantity() << "\n";

    return 0;
}
