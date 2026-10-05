#include <iostream>
#include <unordered_map>

/*
Concept: std::unordered_map - fast lookup by key, no ordering

std::unordered_map<Key, Value> gives average O(1) lookup/insert/erase by key,
using a hash table internally. Unlike std::map, it does NOT keep entries
sorted - iterating one gives entries in some unspecified order. You use it
when you only care about "give me the value for this key, fast", not about
order.

Why the order book needs one: a trader cancels an order by its ID, e.g.
"cancel order #42". Without an index, finding order #42 would mean scanning
every price level's list until you find it - slow if there are many levels.
An unordered_map<int, ...> from order ID straight to "where it lives" turns
that into a single O(1) lookup.

std::unordered_map<int, double> order_to_price;
order_to_price[42] = 100.50;        // order 42 is resting at price 100.50
auto it = order_to_price.find(42);
if (it != order_to_price.end()) {
    std::cout << "order 42 is at price " << it->second << "\n";
}
order_to_price.erase(42);           // remove the index entry once the order is gone
*/

/*
Exercise 4:

1. Create a std::unordered_map<int, double> called orderToPrice, mapping an
   order ID to the price it's resting at.
2. Insert at least 4 orders with made-up IDs and prices.
3. Look up one specific order ID with .find(), check it's not .end(), and
   print its price.
4. Try looking up an ID you never inserted, and confirm (print a message)
   that .find() correctly returns .end() for it instead of crashing.
5. Erase one order by ID and confirm with another .find() that it's gone.
*/

int main() {
    return 0;
}
