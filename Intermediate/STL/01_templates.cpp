#include <iostream>

/*
Concept: Function and class templates

A template lets you write one piece of code that works for any type, without
rewriting it per type. The compiler generates a real version for each type you
actually use it with, at compile time - this is "generic programming".

template <typename T>
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}
maxOf(3, 5);        // T = int
maxOf(3.1, 2.9);     // T = double

Class templates work the same way:

template <typename T>
class Box {
public:
    Box(T value) : value_(value) {}
    T get() const { return value_; }
private:
    T value_;
};
Box<int> b1(5);
Box<std::string> b2("hello");

This matters for your order book because std::map, std::queue, std::list, and
std::vector are ALL class templates - std::map<double, int> and
std::map<std::string, int> are two different compiler-generated classes from
the same template. Understanding templates is what makes the STL's containers
make sense, rather than feeling like magic syntax.
*/

/*
Exercise 1:

Write a class template Wrapper<T> that stores one value of type T and has:
1. A constructor taking a T.
2. A method describe() that prints the stored value.

In main(), you'll use it with two unrelated small structs, to prove the same
template works for both without any code duplication:

struct Order { std::string symbol; double price; };
struct Trade { int quantity; double price; };

Define print-friendly operator<< overloads for Order and Trade (or just print
their fields manually inside describe() with a stream), create a
Wrapper<Order> and a Wrapper<Trade>, and call describe() on each.
*/

int main() {
    return 0;
}
