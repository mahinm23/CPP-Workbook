#include <iostream>
#include <vector>
#include <algorithm>

/*
Final check: "am I ready to leave OOP"

This mixes everything from 01-07. No new concepts here, no new explanation -
if you can do this cleanly without having to re-read earlier files, you're solid.
If you get stuck on something specific, that's exactly the gap to go re-drill in
the matching numbered file before moving on to STL/templates/references/smart pointers.

Build a tiny mock order book:

1. Base class Order (encapsulation: private members symbol, price, quantity, with
   a constructor and const getters; polymorphism: virtual print() and a virtual
   destructor).

2. Two derived classes, BuyOrder and SellOrder (inheritance: both chain to Order's
   constructor via the initializer list). Each overrides print() to show its side
   ("BUY"/"SELL") along with symbol/price/quantity.

3. operator<overloading: give Order (or a free function taking two Order*) a way
   to compare two orders by price, so a vector of them can be sorted ascending by
   price. Also add operator<< so an Order can be printed with std::cout <<.

4. Rule of three: this one doesn't need to manage a raw resource itself, so you do
   NOT need custom copy/move members here - but be ready to explain OUT LOUD why
   not (what would make it necessary, and what would break if it needed one but
   didn't have it).

5. In main():
   - Create a std::vector<Order*> containing a mix of BuyOrder and SellOrder
     objects (raw pointers + new, as in exercise 5).
   - Sort the vector by price.
   - Loop through and print each one using polymorphic dispatch (through the
     Order* - confirm BUY/SELL prints correctly per actual object type).
   - Clean up with delete for each pointer.

When this runs correctly and you can explain each numbered concept above without
looking it up, you're done with OOP for now.
*/

int main() {
    return 0;
}
