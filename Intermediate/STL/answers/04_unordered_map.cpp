// Reference solution for ../04_unordered_map.cpp

#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, double> orderToPrice;

    orderToPrice[1] = 150.5;
    orderToPrice[2] = 149.75;
    orderToPrice[3] = 151.0;
    orderToPrice[4] = 148.25;

    auto it = orderToPrice.find(2);
    if (it != orderToPrice.end()) {
        std::cout << "order 2 price: " << it->second << "\n";
    }

    auto missing = orderToPrice.find(999);
    if (missing == orderToPrice.end()) {
        std::cout << "order 999 not found\n";
    }

    orderToPrice.erase(2);
    auto afterErase = orderToPrice.find(2);
    std::cout << (afterErase == orderToPrice.end()
                      ? "order 2 erased\n"
                      : "order 2 still present\n");

    return 0;
}
