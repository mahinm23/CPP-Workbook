#include <iostream>
#include <vector>
#include <algorithm>

/*
Concept: Operator overloading

C++ lets you define what operators like <, ==, << mean for your own types, by
writing them as functions named operator<, operator==, operator<<.

This matters directly for your order book: std::sort and comparisons need to know
how to order your objects, and operator< is what they use by default.

class Point {
public:
    Point(int x) : x_(x) {}
    bool operator<(const Point& other) const {
        return x_ < other.x_;
    }
private:
    int x_;
};

// operator<< is usually written as a free function (not a member), because the
// left-hand side is std::ostream (cout), not your class:
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "Point(" << p.getX() << ")";
    return os;
}
*/

/*
Exercise 6:

Write a class PriceLevel with members double price and int quantity, a constructor,
and getters.

1. Add bool operator<(const PriceLevel& other) const that compares by price.
2. Add bool operator==(const PriceLevel& other) const that returns true if price
   AND quantity both match.
3. Write a free function operator<< that prints a PriceLevel as something like
   "$150.50 x 100".
4. In main(), build a std::vector<PriceLevel> with a few entries in random price
   order, use std::sort(vec.begin(), vec.end()) to sort them (this only works
   because of step 1), then loop and print each one using std::cout << level
   (this only works because of step 3).
*/

int main() {
    return 0;
}
