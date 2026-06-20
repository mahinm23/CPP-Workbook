---
title: Unit 3 — Making Decisions, More on Functions and Records (C++)
date: 18-06-2026
tags: [cpp, unit3, conditionals, functions, records]
status: active
---

# Unit 3: Making Decisions, More on Functions and Records

## Learning Outcomes
- Read and write programs that make decisions
- Explain the use of boolean expressions
- Explain what is meant by if statements
- Trace / dry run programs containing if statements
- Read & write functions that take arguments and return results
- Read & write programs that use accessor functions

---

## Core Concept: Decisions

Straight-line programs aren't enough — programs need to behave differently depending on circumstances (a cash machine asking "cash or balance?", a login checking a password). C++'s `if` statement, like Java's, lets you branch.

## C++ Syntax Reference

### if / else
```cpp
if (<test>) {
    <statement(s)>
} else {
    <statement(s)>
}
```

```cpp
#include <iostream>
#include <string>

std::string ans;
std::cout << "Can I insult you, please?" << std::endl;
std::getline(std::cin, ans);

if (ans == "yes") {
    std::cout << "You smell!" << std::endl;
} else {
    std::cout << "You smell of roses!" << std::endl;
}
std::cout << "Thank you!" << std::endl;
```

### Chained tests
```cpp
if (ans == "yes") {
    std::cout << "You smell!" << std::endl;
} else if (ans == "no") {
    std::cout << "You smell of roses!" << std::endl;
} else {
    std::cout << "yes or no!" << std::endl;
}
```
Always add a final `else` catch-all where input is unpredictable — this is **input validation**, part of defensive programming.

### Boolean expressions and operators
```cpp
letter == 'y'      // equal — comparison
x <= 34             // less than or equal
x * y > 0           // greater than
ans == "yes"        // string comparison (see below)
```
Comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=`

Boolean connectives (Java calls them this too):
```cpp
ans == 'y' || ans == 'Y'   // or
x > 0 && y > 0              // and
!finished                   // not
```

### Comparing strings — easier than Java
Java needs `.equals()` for strings because `==` only compares object identity for non-primitive types. **C++'s `std::string` overloads `==` to compare contents directly** — no separate method needed:
```cpp
std::string pet = "dog";
if (pet == "dog") { ... }   // works correctly, unlike Java's pet == "dog"
```
This is one of the rare cases where C++ is *less* gotcha-prone than Java.

### Dry running if statements
Trace by hand: follow only the branch the test takes, write down variable values at each line.
```cpp
int weight;
int price = 0;
std::cout << "Weight?" << std::endl;
std::cin >> weight;

if (weight <= 5) {
    price = 2;
} else if (weight <= 10) {
    price = 4;
} else {
    price = 6;
}
std::cout << "The cost is " << price << std::endl;
```
Trace this for inputs 3, 10, and 11 by hand before running it.

---

## Functions That Return Results

A **function** computes and returns a value; a **procedure** (`void` return type) just does something. Define a return type matching whatever follows `return`:

```cpp
int calculateAverage() {
    int value1, value2, average;

    std::cout << "Give me the first" << std::endl;
    std::cin >> value1;
    std::cout << "Give me the second" << std::endl;
    std::cin >> value2;

    average = (value1 + value2) / 2;
    return average;
}
```

### Passing arguments
Rather than rewriting near-identical input code, **generalise** with a parameter:
```cpp
int inputInt(std::string message) {
    std::cout << message << std::endl;
    int value;
    std::cin >> value;
    return value;
}

int calculateAverage() {
    int value1 = inputInt("Give me the first");
    int value2 = inputInt("Give me the second");
    return (value1 + value2) / 2;
}
```
A change to `inputInt` (e.g. adding validation) now improves every place that calls it — write once, fix once.

---

## Accessor Functions on Records (recap from Unit 2)

```cpp
struct Student { std::string name; std::string id; int mark; };

std::string getName(Student s) { return s.name; }
Student setName(Student s, std::string n) { s.name = n; return s; }
```
The main program never touches `s.name` directly — only the accessor functions know the internal layout. If the record's structure changes later (e.g. splitting `mark` into `mark1`/`mark2`), only the accessors need editing.

```cpp
struct Student { std::string name; std::string id; int mark1; int mark2; };
int getMark(Student s) { return s.mark1 + s.mark2; }   // callers don't notice the change
```

---

## Decomposition and Abstraction

Splitting a program into functions to do well-defined tasks is **decomposition**. **Abstraction** means hiding detail behind a name — you call `printInsultingMessage()` without needing to know what it prints, just that it does the right thing.

```cpp
#include <iostream>
#include <string>

void printInsultingMessage() {
    std::cout << "You smell!" << std::endl;
    std::cout << "I mean it!" << std::endl;
}

void printNiceMessage() {
    std::cout << "You smell of roses!" << std::endl;
    std::cout << "Wow!!" << std::endl;
}

void insultMe() {
    std::string ans;
    std::cout << "Can I insult you, please?" << std::endl;
    std::getline(std::cin, ans);

    if (ans == "y") {
        printInsultingMessage();
    } else {
        printNiceMessage();
    }
    std::cout << "Bye!" << std::endl;
}

int main() {
    insultMe();
    return 0;
}
```

---

## Exercises

### Exercise 1: Question and response
Ask "How many beans make five?". If the user responds 5, print "Correct!", else "Wrong!". Then change it so 4 or 6 also gets "About right!".

### Exercise 2: Maximum of two integers
Ask for two integers, print the larger.

### Exercise 3: Maximum of three integers
Ask for three integers, print the largest.

### Exercise 4: Pass or fail (grading)
Given a score 0–100, print a letter grade: <40 F, 40-44 E, 45-49 D, 50-59 C, 60-69 B, 70+ A.

### Exercise 5: Postage
Compute parcel postage: first kg £6, each additional kg up to 5kg £4, each kg after that £3 each, up to a max of 20kg (print a "maximum weight" message if exceeded).

### Exercise 6: The planets
Ask for a planet name, print its position from the sun (e.g. "Yes, Mars is the 4th planet from the sun."). If the input isn't a real planet, print "No. X is not a planet."

### Exercise 7: Using functions
Redo exercises 2-6 using functions for the sub-tasks that return results, rather than one big block.

### Exercise 8: Modified Student record
Extend the Student record example to also print the individual coursework and exam marks, not just the total — add extra getter functions.

### Exercise 9: Planet records
Create a `struct Planet` with name, distance from sun, and position. Store Earth's data (3rd, 150 million km) and print it via accessor functions. Redo the planets exercise using this record type.

### Exercise 10: Days in a month
Ask for a month number (1-12), print the number of days (28 or 29 for February). Validate the input is in range 1-12.

### Exercise 11: Leap year
Ask for a year, print whether it's a leap year. A year is a leap year if divisible by 4 and not by 100, unless also divisible by 400. Use `%` for divisibility checks (`x % 4 == 0`).

### Exercise 12: Pounds and pence
Given a price in pence, print it formatted as pounds and pence (e.g. 1415 → £14.15). Use integer division (`/ 100`) and remainder (`% 100`).

### Exercise 13: Inland revenue
Given an annual income, compute tax: £4200 tax-free, next £4500 at 20%, next £22,600 at 23%, remainder at 40%.

---

## Exam Style Question

**Question 1 [25 marks]** — programs making decisions.

**a. [6 marks]** Explain, with examples: i) a type, ii) a boolean expression.

**b. [9 marks]** Give an initial value for `x` in each example below that would lead to `"Hello"` being printed, justifying your answer:
```cpp
i)   if (x == 0)  { std::cout << "Hello" << std::endl; }
ii)  if (x < 5)   { std::cout << "Hello" << std::endl; }
iii) if (x > 11)  { std::cout << "Goodbye" << std::endl; } else { std::cout << "Hello" << std::endl; }
iv)  if (x > 11 && x < 20) { std::cout << "Goodbye"; }
     else if (x > 2)       { std::cout << "Hello"; }
     else                   { std::cout << "Goodbye"; }
```

**c. [10 marks]** Write a C++ program given two integers by the user: a day of the week (1-7, 1=Monday) and a month (1-12). Print the text equivalent, e.g. "A monday in December".

**Question 2 [25 marks]** — defining and using records.

**a. [4 marks]** Explain what is meant by the fields of a record, with examples.

**b. [5 marks]** Explain why accessor functions are an important form of abstraction when a program changes, with an example.

**c. [6 marks]** Compare and contrast functions that get and set record fields.

**d. [10 marks]** Write a C++ program about deadly animals. Define a record storing an animal's name and a "deadly score" (0-10) for at least 5 animals. The user names an animal; the program prints its info, using accessor functions throughout.
