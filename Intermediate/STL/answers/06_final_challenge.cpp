// Reference solution for ../06_final_challenge.cpp

#include <iostream>
#include <map>
#include <list>
#include <unordered_map>
#include <string>

struct OrderLocation {
    double price;
    std::list<std::string>::iterator it;
};

std::map<double, std::list<std::string>, std::greater<double>> bids;
std::unordered_map<std::string, OrderLocation> index;

void addOrder(double price, const std::string& id) {
    auto it = bids[price].insert(bids[price].end(), id);
    index[id] = {price, it};
}

void cancelOrder(const std::string& id) {
    auto locIt = index.find(id);
    if (locIt == index.end()) return;

    double price = locIt->second.price;
    bids[price].erase(locIt->second.it);

    if (bids[price].empty()) {
        bids.erase(price);   // whole level disappears once its last order is gone
    }

    index.erase(locIt);
}

void printBook() {
    for (const auto& [price, ids] : bids) {
        std::cout << price << ": ";
        for (const auto& id : ids) std::cout << id << " ";
        std::cout << "\n";
    }
}

int main() {
    addOrder(150.25, "order-1");
    addOrder(150.25, "order-2");
    addOrder(149.75, "order-3");
    addOrder(151.00, "order-4");
    addOrder(151.00, "order-5");

    std::cout << "initial book:\n";
    printBook();

    cancelOrder("order-2");   // not at the front of its level

    std::cout << "\nafter cancelling order-2:\n";
    printBook();

    cancelOrder("order-3");   // the only order at its price level

    std::cout << "\nafter cancelling order-3 (whole level gone):\n";
    printBook();

    return 0;
}
