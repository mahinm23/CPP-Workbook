// Reference solution for ../03_list_vs_queue.cpp

#include <iostream>
#include <list>
#include <algorithm>
#include <string>

int main() {
    std::list<std::string> priceLevel = {"order-3", "order-7", "order-12"};

    std::cout << "before cancel:\n";
    for (const auto& id : priceLevel) std::cout << id << "\n";

    auto it = std::find(priceLevel.begin(), priceLevel.end(), "order-7");
    if (it != priceLevel.end()) priceLevel.erase(it);

    std::cout << "after cancel:\n";
    for (const auto& id : priceLevel) std::cout << id << "\n";

    // Point 5: std::queue only exposes front()/back()/push()/pop() - no iterators and no
    // erase() for an arbitrary element. There'd be no way to remove "order-7" specifically
    // without popping everything in front of it off first, which isn't a real cancel.

    return 0;
}
