#include <iostream>

/*
Concept: Encapsulation and access specifiers

private members can only be touched from inside the class (or by friends/derived
classes, for protected). public members are the class's external interface.

Encapsulation isn't just "hide the data" for its own sake - it's about protecting
invariants. If quantity is public, nothing stops someone writing order.quantity = -50.
If it's private with a setter, the setter can refuse bad values and the class
guarantees its own data is always valid.

class Point {
public:
    Point(int x, int y) : x_(x), y_(y) {}
    int getX() const { return x_; }   // const: this method promises not to modify the object
    void setX(int x) { x_ = x; }
private:
    int x_, y_;
};
*/

/*
Exercise 3:

Write a class Order with PRIVATE members: std::string symbol, double price, int quantity.

1. Add a constructor that takes all three.
2. Add public getters: getSymbol(), getPrice(), getQuantity() - each should be const
   (they don't modify the object).
3. Add a public setter setQuantity(int q) that only updates quantity if q >= 0.
   If q < 0, print an error message and leave quantity unchanged.
4. In main(), create an Order, try setQuantity(-10) and confirm it's rejected,
   then setQuantity(50) and confirm it works, printing the getter results each time.
*/

int main() {
    return 0;
}
