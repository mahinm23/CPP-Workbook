#include <iostream>
#include <list>
#include <queue>

/*
Concept: std::list vs std::queue - why "cancel" rules out queue

std::queue is strictly FIFO (first in, first out) - you can only look at/remove
the FRONT element. There is no way to reach into the middle and remove one
specific item. That's fine for a pure "process in arrival order" scenario, but
not fine for an order book: a trader can CANCEL any resting order at any time,
not just the oldest one at that price level. If order #3 arrived first, order
#7 arrived second, and the trader cancels #3, you need to remove #3 specifically
and leave #7 in place - std::queue cannot do that.

std::list is a doubly-linked list. Given an iterator to any element (not just
the front), you can erase it in O(1) - no shifting of other elements, because
nothing else in the list has to move:

std::list<int> orders = {3, 7, 12};
auto it = orders.begin();   // points at 3
orders.erase(it);           // removes 3 specifically, 7 and 12 are untouched

This is exactly the queue -> list swap the order-book roadmap calls out as a
deliberate design decision: queue for "insert fast, FIFO only", list for
"insert fast AND remove any specific element fast, given its iterator".
*/

/*
Exercise 3:

1. Create a std::list<std::string> called priceLevel representing order IDs
   resting at one price, in arrival order, e.g. {"order-3", "order-7", "order-12"}.
2. Print the whole list in order (this is what "time priority" at a price
   level looks like - whoever is at the front gets matched first).
3. Simulate a CANCEL of the middle order: get an iterator to "order-7"
   (std::find works on a list) and erase it with priceLevel.erase(it).
4. Print the list again and confirm "order-7" is gone but "order-3" and
   "order-12" are both still there, in their original relative order.
5. In a comment, write one sentence explaining why you could NOT have done
   step 3 if priceLevel had been a std::queue instead.
*/

int main() {
    return 0;
}
