#include <iostream>
#include <vector>

/*
Concept: Polymorphism and virtual functions

Without "virtual", calling a method through a base class pointer always runs the
BASE class's version, even if the pointer actually points at a derived object.
Marking a base method virtual makes C++ look up the ACTUAL object's type at
runtime and call the right override - this is "dynamic dispatch".

class Shape {
public:
    virtual void draw() { std::cout << "shape\n"; }
    virtual ~Shape() {}   // virtual destructor - see note below
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "circle\n"; }   // override: compiler checks
};                                                          // this actually matches a
                                                             // virtual base method - catches typos

Shape* s = new Circle();
s->draw();      // prints "circle", not "shape" - this only works because draw() is virtual

Why the virtual destructor matters: if Shape's destructor is NOT virtual and you
"delete s;" through a Shape*, only Shape's destructor runs - Circle's part of the
object never gets cleaned up properly. Any class meant to be used polymorphically
(through base pointers) needs a virtual destructor.
*/

/*
Exercise 5:

Using the Order / LimitOrder / MarketOrder classes from exercise 4:

1. Make Order's print() virtual, and give Order a virtual destructor.
2. Add override to LimitOrder's and MarketOrder's print().
3. In main(), create a std::vector<Order*> and push_back a LimitOrder* and a
   MarketOrder* onto it (using new).
4. Loop over the vector and call print() on each element through the Order*
   - confirm each one prints its OWN version, not Order's.
5. Loop again and delete each pointer (manual cleanup - we're doing this with raw
   pointers for now; smart pointers that do this automatically come later).
*/

int main() {
    return 0;
}
