#include <iostream>
#include <map>

/*
Concept: std::map and custom comparators

std::map<Key, Value> keeps its entries sorted by key at all times - every
insert, lookup, and iteration respects that order. By default it sorts
ascending (smallest key first), using operator< behind the scenes. You can
swap in a different comparator as a third template argument:

std::map<double, int> ascending;              // default: smallest price first
std::map<double, int, std::greater<double>> descending;  // largest price first

Why this matters for an order book: a bid is a BUY order, an ask is a SELL
order. Buyers want to pay as little as possible, sellers want to receive as
much as possible, so the two sides of the book have opposite "best price":
- Best ASK = the LOWEST price any seller will accept  -> ascending map is correct
- Best BID = the HIGHEST price any buyer has offered   -> needs a DESCENDING map,
  so the best bid is still the first entry when you iterate or call begin()

std::map<double, int, std::greater<double>> bids;
bids[100.50] = 10;
bids[101.00] = 5;
bids.begin();   // -> {101.00, 5}, the highest price, because of greater<double>
*/

/*
Exercise 2:

Build a one-sided order book price ladder:
1. Create a std::map<double, int, std::greater<double>> called bids, where the
   key is a price and the value is the TOTAL quantity resting at that price.
2. Insert at least 4 different price levels with made-up quantities.
3. Loop over the map with a range-based for loop (for (const auto& [price, qty] : bids))
   and print each level.
4. Confirm by eye that the highest price printed first, and prices print in
   descending order overall - that's the comparator doing its job, you didn't
   sort anything yourself.
5. Print bids.begin()->first and bids.begin()->second specifically, labelled
   as "best bid", to show it's always the first entry without you tracking it.
*/

int main() {
    return 0;
}
