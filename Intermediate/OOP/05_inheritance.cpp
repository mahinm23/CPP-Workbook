#include <iostream>

/*
Concept: Inheritance

A derived class reuses and extends a base class. protected members are visible
to derived classes but not from outside the class hierarchy (unlike private).

A derived class's constructor must initialize its base class - usually via the
base class's own constructor, in the derived constructor's initializer list:

class Animal {
public:
    Animal(std::string name) : name_(name) {}
protected:
    std::string name_;
};

class Dog : public Animal {
public:
    Dog(std::string name) : Animal(name) {}   // constructor chaining
    void bark() { std::cout << name_ << " says woof\n"; }
};

"public Dog : public Animal" means Dog IS-AN Animal, and Animal's public members
stay public in Dog. (There's also private/protected inheritance, rarely used -
don't worry about those for now.)
*/

/*
Exercise 4:

1. Write a base class Order with PROTECTED members std::string symbol, int quantity,
   a constructor for both, and a method print() that prints symbol and quantity.

2. Write a derived class LimitOrder : public Order that adds a PRIVATE member
   double price, with its own constructor that chains to Order's constructor
   via the initializer list, and its own print() that prints symbol, quantity,
   AND price.

3. Write a second derived class MarketOrder : public Order that adds nothing new
   - market orders execute at best available price, so there's no price field.
   Give it a constructor that just chains to Order's.

4. In main(), create one LimitOrder and one MarketOrder, and call print() on each.
*/

int main() {
    return 0;
}
