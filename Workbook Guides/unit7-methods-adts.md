---
title: Unit 7 — Functions & Abstract Data Types (C++)
date: 18-06-2026
tags: [cpp, unit7, functions, adt, structs]
status: active
---

# Unit 7: More on Functions, Abstract Data Types

## Learning Outcomes
- Read, write and debug programs split into functions
- Read, write and debug programs that pass information to functions using parameters
- Explain what is meant by a function, procedure and parameter
- Explain what is meant by an abstract data type (ADT)
- Explain how ADTs can be implemented from existing types
- Read, write and debug programs that create and use ADTs

---

## Core Concept: Functions and Procedures

Java's "method" terminology maps directly onto C++ **functions**:
- A **function** computes and returns a value (Java: non-`void` method).
- A **procedure** just does something, returning nothing (Java/C++: `void`).

A function/procedure has two parts:
- **Header** (the *signature*) — name, parameter types, return type
- **Body** — the code that runs, using only its parameters and local variables

```cpp
// Header: int fahrenheitToCelsius(int fahrenheit)
// Body:
int fahrenheitToCelsius(int fahrenheit) {
    int celsius = ((fahrenheit - 32) * 5) / 9;
    return celsius;
}
```

C++ has no `public static` clutter on free functions — just return type, name, parameters.

### Scoping rule (same in both languages)
A variable declared inside a function only exists inside that function. Two different
functions can both have a local variable called `length` — they are not the same variable
just because they share a name.

---

## C++ Syntax Reference

### Function vs procedure
```cpp
// Function — returns int, used in an expression
int square(int n) {
    return n * n;
}

// Procedure — returns nothing, used as a statement
void printSquare(int n) {
    std::cout << n * n << std::endl;
}
```

### Where functions live
In C++, free functions are declared outside `main` and outside any other function —
you cannot nest function definitions. Order matters: a function must be declared (or at
least its signature given, e.g. a forward declaration) before it's used, unlike Java where
order within a class doesn't matter.

### Pass by value — the warning from the workbook
Just like Java, C++ function parameters are **pass by value by default**: the parameter
gets a *copy* of the argument. A function cannot change the caller's variable through a
plain value parameter.
```cpp
void wontWork(int n) {
    n = n + 1;     // only changes the local copy
}
int a = 5;
wontWork(a);
// a is still 5
```
Functions *can* hand a new value back via `return`, exactly like Java:
```cpp
int plusOne(int n) {
    return n + 1;
}
int a = 5;
a = plusOne(a);   // now a is 6
```
The one thing C++ adds that Java doesn't have (covered in Unit 8) is `int&` reference
parameters, which *do* let a function change the caller's variable directly.

### When should something be a function?
Good candidates:
- It performs one clear task you could comment in a single line
- It doesn't depend on a huge number of variables
- You find yourself writing the same code more than once

### Refactoring in-line code into a function
```cpp
// before — inline
int length = 5;
for (int i = 0; i < length; i++) {
    std::cout << myArray[i] << " ";
}

// after — pulled into a function, parameter renamed to `a`
void printArray(int a[], int length) {
    for (int i = 0; i < length; i++) {
        std::cout << a[i] << " ";
    }
}
// call site:
printArray(myArray, length);
```

---

## Core Concept: Abstract Data Types (ADTs)

An **ADT** is a data type defined only by the *operations* you can perform on it —
the implementation is hidden. You've already been using ADTs without realizing it:
- `std::string` — you know `+`, `==`, `.length()`, but not how characters are stored underneath
- `std::vector` — you know `push_back`, `[]`, `.size()`, but not whether it secretly
  reallocates and copies when it grows

The benefit: as long as everyone only uses the *operations*, the underlying
representation can be changed later without breaking anything else.

### Implementing an ADT in C++ (procedural style, no classes)
Same trick the workbook uses in Java (a record + a fixed set of functions that are the
*only* things allowed to touch its fields): in C++ this is a `struct` plus free functions.
This is exactly the pattern already used for the `Queue` ADT in `unit8-references-pointers.md`
— that example **is** the ADT pattern for this unit, just introduced a unit early because it
also needed pass-by-reference. The rule going forward: **only the defining functions touch
the struct's fields directly; everything else calls those functions.**

```cpp
struct Queue {
    std::string entries[10];
    int numberQueueing;
};

Queue createEmptyQueue();                          // make a new, empty queue
void joinQueue(Queue& q, std::string newEntry);     // add to the back
std::string leaveQueue(Queue& q);                   // remove from the front
std::string firstInQueue(Queue& q);                 // peek at the front, unchanged
```
Calling code never touches `q.entries` or `q.numberQueueing` directly — it only calls
these four functions. You could swap the internal array for something else entirely and
nothing outside this set of functions would need to change.

---

## Exercises

### Exercise 1: Hello procedure
Write a procedure `hello(std::string name)` that prints `"Hello " + name`. Call it twice
from `main` with your own name.

### Exercise 2: Simple calculation
Write a function `plusOne(int a)` that returns `a + 1`. Write a program that reads an
integer and prints the result of calling it.

### Exercise 3: Sum to n
The sum of the first `n` numbers is `n * (n + 1) / 2`. Write a function `sumToN(int n)`
that calculates this, and test it with `sumToN(1)`, `sumToN(5)`, `sumToN(10)`.

### Exercise 4: Repeated sum to n
Extend Exercise 3 with a loop that calls `sumToN` for every value from 1 to 10 and
prints each result.

### Exercise 5: Printing characters
Write a procedure `printChar(char c, int n)` that prints character `c`, `n` times
(no newline). Use it to:
- (a) print an `m`-by-`n` rectangle of `*`s
- (b) print an `m`-line right-angled triangle of `*`s (right angle at bottom-right)

### Exercise 6: Queue front-end
Using the existing `Queue` functions from Unit 8 (don't modify them), write a menu-driven
program: options to join the queue, leave the queue, or quit — always printing who's at
the front.

### Exercise 7: Medal winners ADT (main exercise)
Design a new ADT, `Olympians`, that stores each athlete's name and best medal
(Gold/Silver/Bronze). Use one or more arrays as the underlying struct fields. Required
operations:
- `createEmptyDatabase()`
- `addRecord(db, name, medal)`
- `highestMedalOf(db, name)`

```cpp
#include <iostream>
#include <string>

const int MAX = 50;

struct Olympians {
    std::string names[MAX];
    std::string medals[MAX];
    int count;
};

Olympians createEmptyDatabase() {
    // YOUR CODE
}

void addRecord(Olympians& db, std::string name, std::string medal) {
    // YOUR CODE
}

std::string highestMedalOf(Olympians& db, std::string name) {
    // YOUR CODE — linear search by name, return their medal (or "unknown")
}

int main() {
    Olympians db = createEmptyDatabase();
    addRecord(db, "Sarah Storey", "Gold");
    addRecord(db, "Kadeena Cox", "Silver");
    std::cout << highestMedalOf(db, "Sarah Storey") << std::endl;
    return 0;
}
```

### Exercise 8: Endangered animals as an ADT
Take the `extinct` / `endangered` / `vulnerable` / `notInDanger` lookup functions
(hard-coded `if` checks in the workbook) and replace them with a proper ADT: a hidden
array-backed database with an `addAnimal(db, name, status)` operation, so the status
data is stored rather than hard-coded in `if` statements.

### Exercise 9: Stacks
Implement a `Stack` ADT (last-in-first-out) — the entry removed is always the most
recently added one. Mirror the `Queue` struct/function pattern: `createEmptyStack()`,
`push(s, value)`, `pop(s)`, `top(s)`.

### Exercise 10: Rotate vowels
Read a sentence from the user and rotate its lower-case vowels: `a→e, e→i, i→o, o→u, u→a`.
Write a helper function to test whether a character is a lower-case vowel, and another to
do the rotation.

### Exercise 11: Quadratics
Read three integers `a`, `b`, `c` and describe the roots of `ax² + bx + c`, using a
function to compute the discriminant `b² - 4ac`:
- `> 0` → two real roots
- `== 0` → one repeated real root
- `< 0` → two imaginary roots

### Exercise 12: Raster triangles
Write a program that prints rows of triangles built from `*` characters, given:
(a) the triangle size, (b) triangles per row, (c) number of rows. Use your `printChar`
function from Exercise 5 to draw each line.

---

## Exam Style Question: Functions / Abstract Data Types

**Question 1** [25 marks]

**a.** [6 marks] Compare and contrast a function call and a procedure call, illustrating
with examples.

**b.** [9 marks] Rewrite the following so it doesn't call the function `convert`, but
behaves identically. Explain each step of the conversion (i.e. inline the function body).
```cpp
int main() {
    std::cout << "Give me a temperature in F: ";
    int temp;
    std::cin >> temp;
    convert(temp);
    return 0;
}

void convert(int fahrenheit) {
    int newtemp = (fahrenheit - 32) * 5 / 9;
    std::cout << "That is " << newtemp << "C" << std::endl;
}
```

**c.** [10 marks] A garage sells used cars at a discount: 10% off the full price, plus a
further discount equal to the trade-in price of any car the customer is exchanging. Write
a function that calculates the final price given the full price and trade-in price (both
parameters). Write a `main` that calls it repeatedly with keyboard input until the user
quits.

**Question 2** [25 marks]

**a.** [9 marks] Using the example of a priority queue (entries leave in priority order,
not arrival order), explain how functions can be used to create an ADT that hides a data
structure's implementation from the rest of the program.

**b.** [6 marks] Justify the claim: "Abstract data types help make programs easier to
write, understand, and change."

**c.** [10 marks] Write a program that answers queries about the zones of overground
stations. It should provide a menu (add a station, look up a station's zone, or quit).
Store the underlying station data as an array of structs, but access it **only** through
an ADT's functions, so the representation could be changed later without affecting the
menu code.
