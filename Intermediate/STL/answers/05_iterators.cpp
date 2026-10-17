// Reference solution for ../05_iterators.cpp

#include <iostream>
#include <list>
#include <unordered_map>
#include <string>

int main() {
    std::list<std::string> priceLevel;
    std::unordered_map<std::string, std::list<std::string>::iterator> index;

    for (const std::string& id : {std::string("order-1"), std::string("order-2"), std::string("order-3")}) {
        auto it = priceLevel.insert(priceLevel.end(), id);
        index[id] = it;
    }

    std::cout << "before:\n";
    for (const auto& id : priceLevel) std::cout << id << "\n";

    std::string target = "order-2";
    priceLevel.erase(index[target]);   // O(1) - no find(), no loop
    index.erase(target);               // the iterator is now stale, drop the stale entry too

    std::cout << "after:\n";
    for (const auto& id : priceLevel) std::cout << id << "\n";

    return 0;
}
