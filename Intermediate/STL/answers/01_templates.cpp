// Reference solution for ../01_templates.cpp

#include <iostream>
#include <string>

template <typename T>
class Wrapper {
public:
    Wrapper(T value) : value_(value) {}

    void describe() {
        std::cout << value_ << "\n";
    }

private:
    T value_;
};

struct Order {
    std::string symbol;
    double price;
};

struct Trade {
    int quantity;
    double price;
};

std::ostream& operator<<(std::ostream& os, const Order& o) {
    os << "Order(" << o.symbol << ", " << o.price << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Trade& t) {
    os << "Trade(" << t.quantity << ", " << t.price << ")";
    return os;
}

int main() {
    Wrapper<Order> orderWrapper(Order{"AAPL", 150.5});
    Wrapper<Trade> tradeWrapper(Trade{100, 150.5});

    orderWrapper.describe();
    tradeWrapper.describe();

    return 0;
}
