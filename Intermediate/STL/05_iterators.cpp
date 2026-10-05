#include <iostream>
#include <list>
#include <unordered_map>

/*
Concept: iterators, and storing an iterator as a value

An iterator is a pointer-like object that marks a position inside a
container. begin() marks the first element, end() marks "one past the last" -
the loop condition it != end() is how every STL traversal works underneath a
range-based for loop. For std::map, iterating from begin() to end() always
visits entries in the map's sort order (key order, respecting whatever
comparator it uses) - that's not a coincidence, it's the whole reason a
sorted container is useful for an order book ladder.

The more powerful trick: you can STORE an iterator as a value somewhere else,
and use it later to jump straight to that position without searching again.
This is exactly how exercise 4's unordered_map index should really work - not
mapping order ID -> price, but order ID -> an iterator pointing directly at
that order's node inside its price level's std::list. Then cancelling an
order is: look up the iterator in O(1) via the unordered_map, then erase it
from the list in O(1) via that iterator - no scanning anything.

std::list<std::string> priceLevel = {"order-3", "order-7", "order-12"};
auto it = std::next(priceLevel.begin(), 1);   // iterator pointing at "order-7"
std::unordered_map<std::string, std::list<std::string>::iterator> index;
index["order-7"] = it;
// later, to cancel order-7 with no searching at all:
priceLevel.erase(index["order-7"]);
index.erase("order-7");
*/

/*
Exercise 5:

1. Create a std::list<std::string> called priceLevel with a few order IDs.
2. Create a std::unordered_map<std::string, std::list<std::string>::iterator>
   called index.
3. As you insert each order ID into priceLevel (use push_back, which returns
   nothing, so capture the iterator with a separate call, e.g.
   priceLevel.insert(priceLevel.end(), id) returns the iterator to the newly
   inserted element), store that iterator in index under the same ID.
4. Pick one order ID, look up its iterator in index (O(1)), and use it to
   erase that exact order from priceLevel directly - no std::find, no loop.
5. Print priceLevel before and after to confirm only that one order is gone.
6. Also erase the now-stale entry from index itself (an iterator into a
   container is only valid while that element still exists).
*/

int main() {
    return 0;
}
