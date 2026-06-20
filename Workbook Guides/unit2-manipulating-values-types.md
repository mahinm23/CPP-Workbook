---
title: Unit 2 — Manipulating Values, Using Types (C++)
date: 18-06-2026
tags: [cpp, unit2, types, records]
status: active
---

# Unit 2: Manipulating Values, Using Types

## Learning Outcomes
- Read, write and run simple programs that manipulate data
- Read, write programs that do calculations on values stored
- Read, write programs that print messages including the results of calculations
- Read, write programs that store and manipulate different types of values
- Read, write programs that create and use simple record types
- Explain the importance of types

---

## Core Concept: Types

Grouping values into types with similar properties means the compiler can allocate the right kind of storage, and stop you doing meaningless things (like multiplying two strings together).

## C++ Syntax Reference

### Basic types
```cpp
int x = 5;            // whole numbers
double pi = 3.14159;  // floating point — more accurate than float
char c = 'a';         // single character (note: single quotes)
std::string s = "hi"; // string of characters (note: double quotes)
bool finished = true; // true or false
s```
Note `'a'` (char) is a different type to `"a"` (a one-character string) is a different type to the integer that represents it in ASCII — they're stored and operated on differently.

### Declaring and initializing in one step
```cpp
int count = 1;
std::string film = "The Matrix";
```

### String concatenation
```cpp
std::string greeting = "The Matrix" + std::string(" is cool!");
// or, once a std::string variable exists on one side, + works directly:
std::string msg = film + " is cool!";
```

### Converting text to numbers
Java's `Integer.parseInt` / `Double.parseDouble` become:
```cpp
#include <string>
int i = std::stoi(textInput);       // string to int
double d = std::stod(textInput);    // string to double
```
(In practice, reading directly with `std::cin >> i;` skips this conversion step entirely for numeric input.)

### Expressions
An expression is a fragment that evaluates to a value:
```cpp
(total + 1) * 2     // integer expression
"Hello " + name      // string expression (if name is std::string)
```
Arithmetic follows BODMAS — multiplication/division before addition/subtraction.

### Random numbers
```cpp
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()

srand(time(0));          // seed once, at program start
int diceThrow = rand() % 6 + 1;     // 1 to 6
int bigDiceRoll = rand() % 10 + 1;  // 1 to 10
```
`rand() % 6` gives 0–5; add 1 to get a 1–6 die. (Java's `Random.nextInt(6) + 1` is the direct equivalent.)

---

## Defining Your Own Types: Records (structs)

Java uses a `class` with only fields to make a simple record. C++ has a lighter-weight construct for exactly this: `struct`.

```cpp
struct Student {
    std::string name;
    std::string id;
    int mark;
};
```

This defines a *blueprint* — it doesn't create any variables itself. Create and use one like this:
```cpp
Student s1;
s1.name = "Paul Curzon";
s1.id = "4509930";
s1.mark = 89;
std::cout << s1.id << " " << s1.name << " " << s1.mark << std::endl;
```
Access fields with `.fieldName` — identical syntax to Java's `s1.name`.

### Accessor functions
Good practice: access fields only through functions you write for the purpose, not directly everywhere in your code. This is **abstraction** — it means a later change to the record's internal layout only requires changing the accessor functions, not every place that uses them.

```cpp
std::string getName(Student s) {
    return s.name;
}

Student setName(Student s, std::string newName) {
    s.name = newName;
    return s;
}
```

---

## A Compilable Worked Example

```cpp
#include <iostream>
#include <string>

struct Student {
    std::string name;
    std::string id;
    int mark;
};

std::string getName(Student s) { return s.name; }
std::string getId(Student s)   { return s.id; }
int getMark(Student s)         { return s.mark; }

Student setName(Student s, std::string n) { s.name = n; return s; }
Student setId(Student s, std::string i)   { s.id = i; return s; }
Student setMark(Student s, int m1, int m2) { s.mark = m1 + m2; return s; }

int main() {
    Student s1;
    s1 = setName(s1, "Paul Curzon");
    s1 = setId(s1, "4509930");
    s1 = setMark(s1, 40, 49);

    std::cout << getId(s1) << " " << getName(s1) << " " << getMark(s1) << std::endl;
    return 0;
}
```

---

## Exercises

### Exercise 1: Number input
Write a program that reads a whole number `n` and prints it out again. Modify it to print `n + 1`.

### Exercise 2: Fahrenheit to Celsius
Read a temperature in Fahrenheit, print the Celsius equivalent: `C = (F - 32) * 5 / 9`. Make the prompts user-friendly.

### Exercise 3: Celsius to Fahrenheit
Read a Celsius temperature, print the Fahrenheit equivalent: `F = (C * 9 / 5) + 32`.

### Exercise 4: Area of a rectangle
Read the length and breadth of a rectangle (cm) and compute its area.

### Exercise 5: Rectangle record
Create a `struct Rectangle` holding an integer length and breadth. Ask the user for both, store them in a `Rectangle`, then print the area (using accessor functions).

### Exercise 6: Compiler messages
Take your completed area-of-rectangle program and introduce single errors one at a time (delete a line, mistype a variable name in one place only, delete a bracket, etc). After each change: compile, note the error message, work out what it means, fix it, recompile to confirm, then move to the next error.

### Exercise 7: Bonuses (accuracy)
Write a program that divides a company profit equally between 5 employees as a bonus. Does your program give an accurate answer? If not, consider why — `double` rather than `int` may help.

### Exercise 8: 12-sided dice
Write a program that rolls a 12-sided dice and prints the result.

### Exercise 9: Giving change
Write a program that works out the best way to give change. Given the amount due and the cash received, calculate the difference, then work out how many £1, 50p, 20p, 10p coins etc. are needed. Hint: convert the difference to a whole number of pence first.

### Exercise 10: Funny 6-sided dice
Write a program that rolls a 6-sided die with faces numbered 5, 6, 7, 8, 9, 10.

### Exercise 11: Odd 6-sided dice
Write a program that rolls a 6-sided die with faces numbered 1, 3, 5, 7, 9, 11.

---

## Exam Style Question

**Question 1 [25 marks]** — this question concerns assignment and expressions.

**a. [6 marks]** State whether each of the following are good or bad choices for a variable name, justifying your answer:
i) `t`  ii) `class`  iii) `hair_colour`  iv) `hairColour1`  v) `4cast`  vi) `timeOfDay`

**b. [9 marks]** Compare and contrast the following fragments:
```cpp
i)
t = a;
a = b;
b = t;

ii)
c = d;
d = c;
```

**c. [10 marks]** Write a C++ program that converts a length of time given in days into minutes (1 day = 1440 minutes, since 1×60×24 = 1440).
