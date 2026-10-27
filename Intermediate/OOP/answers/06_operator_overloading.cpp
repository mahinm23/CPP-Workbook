// Reference solution for ../Ex6/06_operator_overloading.cpp

#include <iostream>
#include <vector>
#include <algorithm>

class PriceLevel {
public:
    PriceLevel(double price, int quantity) : price_(price), quantity_(quantity) {}

    double getPrice() const { return price_; }
    int getQuantity() const { return quantity_; }

    bool operator<(const PriceLevel& other) const {
        return price_ < other.price_;
    }

    bool operator==(const PriceLevel& other) const {
        return price_ == other.price_ && quantity_ == other.quantity_;
    }

private:
    double price_;
    int quantity_;
};

// free function: left-hand side is std::ostream, not PriceLevel
std::ostream& operator<<(std::ostream& os, const PriceLevel& level) {
    os << "$" << level.getPrice() << " x " << level.getQuantity();
    return os;
}

int main() {
    std::vector<PriceLevel> levels = {
        PriceLevel(150.25, 100),
        PriceLevel(149.75, 50),
        PriceLevel(151.00, 75)
    };

    std::sort(levels.begin(), levels.end());   // works because of operator<

    for (const auto& level : levels) {
        std::cout << level << "\n";            // works because of operator<<
    }

    return 0;
}
