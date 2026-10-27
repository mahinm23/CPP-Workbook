---
title: OOP 01 - Classes and Objects
date: 27-10-2026
tags: [cpp, oop, intermediate]
status: active
---

# OOP 01: Classes and Objects

## Concept
```cpp
class Order {
public:
    std::string symbol;
    double price;
    int quantity;

    void print() {
        std::cout << symbol << " " << quantity << " @ " << price << "\n";
    }
};

int main() {
    Order o;
    o.symbol = "AAPL";
    o.price = 150.5;
    o.quantity = 100;
    o.print();
}
```

## Exercise
Write a class called `Trade` with members `std::string side` (e.g. "BUY" or "SELL"), `double price`, and `int quantity`. Give it a member function `double notional()` that returns `price * quantity`. Write a small `main()` that creates a `Trade`, sets its fields, and prints the result of `notional()`.

## Starter
Create your own `01_classes_objects.cpp` in this folder. Headers you'll need:
```cpp
#include <iostream>
```

Reference solution: none - solved directly in your own `01_classes_objects.cpp`.
