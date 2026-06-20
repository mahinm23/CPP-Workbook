---
title: Unit 4 — Counter-Controlled (Bounded For) Loops (C++)
date: 18-06-2026
tags: [cpp, unit4, loops]
status: active
---

# Unit 4: Counter-Controlled (Bounded For) Loops

## Learning Outcomes
- Read & write programs that follow instructions a fixed number of times
- Explain what is meant by a for loop
- Trace / dry run the execution of programs containing for loops
- Read & write functions that return results (recap, in loop context)

---

## Core Concept: Doing Things Repeatedly

Writing the same `std::cout` line ten times by hand is long-winded and doesn't scale (what about 1,000,000 times?). A **for loop** packages: a counter that starts somewhere, a test for when to stop, and a step to change the counter each time round.

## C++ Syntax Reference

### For loop — identical to Java
```cpp
for (int i = 1; i <= 10; i++) {
    std::cout << i << ": I must not be late for class" << std::endl;
}
```
This says: start a counter `i` at 1, stop once `i > 10`, increment `i` by 1 each time round. `i++` is shorthand for `i = i + 1`.

General form:
```cpp
for (int i = <start>; i <= <finish>; i++) {
    <body>
}
```
Means: for `i` changing from `<start>` to `<finish>`, do `<body>` each time. Don't manually change `i` inside `<body>` — let the loop header own it.

### Accumulator variables
Build a result up a bit at a time across iterations:
```cpp
int sum = 0;
for (int i = 1; i <= 5; i++) {
    sum = sum + i;
}
std::cout << "The answer is " << sum << std::endl;
```
**Always initialize the accumulator before the loop** — `sum` needs a starting value or the first `sum + i` is undefined.

### Nested for loops
Any commands can go in a loop body, including another loop — this gives you 2D processing:
```cpp
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 5; j++) {
        std::cout << "*";
    }
    std::cout << std::endl;
}
```

---

## Dry Running Loops

Trace by hand, using a table with one column per variable, one row per line executed:

```cpp
int sum = 0;            // L1
for (int i = 1; i <= 2; i++) {   // L2
    sum = sum + i;       // L3
}
std::cout << sum << std::endl;   // L4
```

| LINE | sum | i | notes |
|------|-----|---|-------|
| L1 | 0 | | `i` doesn't exist yet |
| L2 | | 1 | set i=1, test 1<=2 true → enter loop |
| L3 | 1 | | sum = 0 + 1 |
| L2 | | 2 | increment i, test 2<=2 true → loop again |
| L3 | 3 | | sum = 1 + 2 |
| L2 | | 3 | increment i, test 3<=2 false → exit loop |
| L4 | | | prints 3 |

---

## Common Loop Idioms

**Counter-controlled loop** — do something exactly `m` times:
```cpp
for (int i = 1; i <= m; i++) {
    // the thing to do m times
}
```

**Accumulating a result:**
```cpp
for (int i = 1; i <= m; i++) {
    acc = acc + /* calculation */;
}
```

**Conditioned loop** — process something `m` times, but only act if a test on `i` holds (used for searching):
```cpp
for (int i = 1; i <= m; i++) {
    if (/* test depending on i */) {
        // process i
    }
}
```

**Rectangular nested loop** — process an `m` by `n` grid:
```cpp
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        // body
    }
}
```

**Lower triangular** (inner loop bound depends on outer counter — used in faster sort algorithms, see Unit 10):
```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        // body
    }
}
```

**Upper triangular** (inner loop starts at the outer counter):
```cpp
for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
        // body
    }
}
```

---

## Input Validation: Checking a String Is a Positive Integer

```cpp
#include <cctype>   // std::isdigit
#include <string>

bool isPositiveInteger(std::string s) {
    for (int i = 0; i < (int)s.length(); i++) {
        char c = s[i];
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}
```
C++'s `std::isdigit(c)` from `<cctype>` is the direct equivalent of writing your own `isDigit` helper in Java.

---

## Exercises

### Exercise 1: Print your name
Print your name 3 times using a for loop, then modify to print it 6 times. Then print "Starting List" before and "Ending List" after. Then store the repeat count in a variable, then read the repeat count from the user.

### Exercise 2: Punishment message
Print a punishment message of your choice, e.g. `"I must not sleep in class"`, 20 times using a loop.

### Exercise 3: Trace statements
Add `std::cout` trace lines inside a loop to print the value of `i` and any accumulator on each iteration — practice for debugging loops that don't behave as expected.

### Exercise 4: List the integers
Print the integers 1 to 20. Then write a version that reads `n` from the user and prints 1 to `n`.

### Exercise 5: Add the integers
Read a non-negative integer `n`, print the sum of 1 to `n` (e.g. for 5: 1+2+3+4+5=15).

### Exercise 6: Squares
Read a positive integer `n`, print an `n` by `n` square of `'P'` characters. Hint: get a single row of `n` Ps working with one loop first, then wrap a second loop around it.

### Exercise 7: Rectangles
Read two positive integers `m` and `n`, print an `m` by `n` rectangle of `'*'` characters.

### Exercise 8: Multiplication table
Print a multiplication table up to 12 (12 rows, 12 columns) using nested loops.

### Exercise 9: Printing triangles
Read a positive integer `n`, print an `n`-line triangle of `'*'` characters with the right angle in the bottom-left:
```
*
**
***
****
*****
```

### Exercise 10: Repeated dice throws
Throw a 6-sided die 20 times, printing each result. Extend it to count and print how many times each face came up (hint: an array of 6 counters, covered properly in Unit 8).

### Exercise 11 (harder): Clockwork
Write a program simulating a 24-hour digital clock. Read a day of the week (`Mo`, `Tu`, ...) and an hour/minute/second. Advance the clock by 1 second and print the new day/time (e.g. day `Sa`, time 23:59:59 advances to `Su 0 0 0`). Then put the tick inside a for loop and advance it 100 times.

---

## Exam Style Question

**Question 1 [25 marks]** — programs acting repeatedly.

**a. [9 marks]** For each, state how many times `"p"` is printed, justifying your answer:
```cpp
i)
for (int i = 1; i < 4; i++) { std::cout << "p"; }

ii)
for (int i = 1; i < 1; i++) { std::cout << "p"; }

iii)
for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) { std::cout << "p"; }
}

iv)
for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= i; j++) { std::cout << "p"; }
}
```

**b. [6 marks]** The following fragments contain errors. State what the error is and whether the compiler would detect it, justifying your answer:
```cpp
i)
// write Hello 10 times
for (int i = 0; i < 10; i++);
{
    std::cout << "Hello" << std::endl;
}

ii)
// write numbers from 1 to 10
for (int i = 1; i < 10; i++) {
    std::cout << i << std::endl;
}
```

**c. [10 marks]** Write a C++ program that uses a for loop to print the `n` times table, where `n` is supplied by the user. Example run:
```
Which times table should I print? 2
1x2=2  2x2=4  3x2=6  4x2=8  5x2=10
```
