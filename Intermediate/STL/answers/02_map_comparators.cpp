// Reference solution for ../02_map_comparators.cpp

#include <iostream>
#include <map>

int main() {
    std::map<double, int, std::greater<double>> bids;

    bids[150.25] = 100;
    bids[149.75] = 200;
    bids[151.00] = 50;
    bids[148.50] = 300;

    for (const auto& [price, qty] : bids) {
        std::cout << price << " -> " << qty << "\n";
    }

    std::cout << "best bid: " << bids.begin()->first
               << " -> " << bids.begin()->second << "\n";

    return 0;
}
