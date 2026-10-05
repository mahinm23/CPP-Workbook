#include <iostream>
#include <map>
#include <list>
#include <unordered_map>
#include <string>

/*
Final check: "am I ready to leave STL for now"

This mixes everything from 01-05 into the actual shape of one side of the real
order book. No new concepts here - if you can do this cleanly without
re-reading earlier files, you're solid. If you get stuck on something
specific, that's the gap to go re-drill in the matching numbered file before
moving on to references/smart pointers.

Build the bid side of a mini order book:

1. A struct Order { int id; double price; int quantity; } (plain struct is
   fine here, this file is about containers, not classes).

2. std::map<double, std::list<Order>, std::greater<double>> bids - price
   levels sorted so the HIGHEST price is first (exercise 2's comparator),
   each level holding a std::list<Order> in arrival order (exercise 3, so any
   one order can be cancelled without disturbing the others at that level).

3. std::unordered_map<int, std::list<Order>::iterator> orderIndex - maps an
   order ID straight to its exact position inside whichever price level's
   list it lives in (exercise 4's fast lookup + exercise 5's stored iterator).
   Note the index alone doesn't tell you WHICH price level a list::iterator
   belongs to - for this exercise, store a std::pair<double, std::list<Order>::iterator>
   per ID instead, so cancel can find both the price level and the position
   in one lookup.

4. A function addOrder(Order o) that:
   - inserts o into bids[o.price] (creating that price level's list if it
     doesn't exist yet - operator[] on a map does this automatically)
   - records the new order's {price, iterator} pair in orderIndex

5. A function cancelOrder(int id) that:
   - looks up id in orderIndex (if not found, print an error and return)
   - uses the stored price + iterator to erase the order from its list in bids
   - if that price level's list is now empty, erase the whole price level
     from bids (keeps the book from accumulating empty levels)
   - erases the id from orderIndex

6. A function printBook() that loops over bids (highest price first, for
   free, because of the comparator) and for each level prints the price and
   every order ID resting there.

7. In main(): add 5-6 orders across 2-3 different price levels, call
   printBook(), cancel one order that is NOT at the front of its level's
   list, call printBook() again and confirm only that order is gone and the
   others at its level are untouched, then cancel every remaining order at
   one whole price level and confirm that price level disappears from the
   printed book entirely.

When this runs correctly and you can explain WHY each container was chosen
(not just that it works) without looking anything up, you're done with STL
for now - this is close to the real OrderBook class's actual member
variables.
*/

int main() {
    return 0;
}
