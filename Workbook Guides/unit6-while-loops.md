---
title: Unit 6 — While Loops (C++)
date: 18-06-2026
tags: [cpp, unit6, loops, while]
status: active
---

# Unit 6: While Loops

## Learning Outcomes
- Read, write and debug programs that repeat an unknown number of times
- Explain what is meant by `for` loops and `while` loops, and how they differ
- Trace the execution of programs containing while loops

---

## Core Concept: Bounded vs Unbounded Repetition

A `for` loop is great when you know how many times to repeat *before* the loop starts.
Many problems don't give you that — you only know "keep going until some condition holds."
That's what `while` is for. Loops always have two parts:
- **A test** — should we do it again?
- **A body** — the thing to repeat
There's also usually something the loop's body changes that affects the test — the
**accumulator** (a running score, a counter, a flag).

`while` is identical in C++ and Java:
```cpp
while (<condition>) {
    <body>
}
```
Check the condition; if true, run the body, then check again. If false initially,
the body never runs at all ("non-starting loop"). `while (true) { }` never stops on
its own — you'd kill it with Ctrl-C. A correct **algorithm** must terminate; an
infinite loop by definition isn't one.

---

## C++ Syntax Reference

### Basic while loop
```cpp
int count = 0;
std::string ans = "y";
while (ans == "y") {
    count++;
    std::cout << "Shall I go on? (y/n): ";
    std::cin >> ans;
}
std::cout << "That was " << count << " times" << std::endl;
```

### "Just ask" pattern — repeat while the user wants to continue
```cpp
std::string ans = "y";
while (ans == "y" || ans == "Y") {
    // <real work to be repeated goes here>
    std::cout << "Again? (y/n): ";
    std::cin >> ans;
}
```

### Sentinel value pattern — stop on a special input
```cpp
const std::string END = "quit";
std::string ans;
std::cout << "First value: ";
std::cin >> ans;
while (ans != END) {
    // <work to process the value goes here>
    std::cout << "Next value: ";
    std::cin >> ans;
}
```

### Accumulator stopping on a sentinel
```cpp
const int END = 0;
int sum = 0;
int next;
std::cin >> next;
while (next != END) {
    sum += next;
    std::cin >> next;
}
```

### Accumulator stopping at a target value
```cpp
const int LIMIT = 21;
int sum = 0;
int next;
while (sum < LIMIT) {
    std::cin >> next;
    sum += next;
}
```

### Linear search with a while loop (alternative to the for+break version from Unit 5)
```cpp
bool found = false;
int i = 0;
int result = -1;
while (!found && i < size) {
    if (a[i] == target) {
        found = true;
    }
    i++;
}
if (found) result = i - 1;
```
This uses a boolean flag as part of the loop condition — a pattern you'll see often,
not just for search.

---

## While Loops and For Loops Are Equivalent

Any pure `for` loop can be rewritten as a `while`:
```cpp
for (int i = start; i <= finish; i++) {
    body;
}
// is the same as:
int i = start;
while (i <= finish) {
    body;
    i++;
}
```
The reverse isn't true — you can't always force a `while` loop into a pure `for` loop,
because `while` can express things a fixed counter can't (and it's easy to accidentally
write a non-terminating `while`, which is much harder to do with a standard `for`).

This is true in C++ exactly as in Java: `for`, `while`, and sequencing/branching
(`if`) are the only three control constructs you actually need — a language with
just those three is **Turing complete**. Everything else (functions, classes, other
loop types) exists for convenience, not necessity.

---

## Worked Example: Average of pairs of ages (from workbook, translated to C++)

```cpp
#include <iostream>
#include <string>

int calculateAverage(int value1, int value2) {
    return (value1 + value2) / 2;
}

int main() {
    std::string again = "yes";
    while (again == "yes") {
        int age1, age2;
        std::cout << "Give me the first age: ";
        std::cin >> age1;
        std::cout << "Give me the second age: ";
        std::cin >> age2;

        int averageAge = calculateAverage(age1, age2);
        std::cout << "Average: " << averageAge << std::endl;

        std::cout << "Continue? (yes/no): ";
        std::cin >> again;
    }
    return 0;
}
```

---

## Exercises

### Exercise 1: Dice game (roll until a 6)
Assume a function `int diceRoll()` exists that returns a random 1–6. Write a fragment
using a `while` loop that rolls until a 6 comes up, keeping the highest score reached.

### Exercise 2: Read and output until zero
Repeatedly read non-zero integers from the keyboard and print each one. Stop when the
user types 0. Hint: read one value first, then loop while it isn't the sentinel.

### Exercise 3: Repeatedly adding
Read non-zero integers until a zero is typed, then print the **sum** of everything read
(excluding the zero). You need an accumulator inside the loop.

### Exercise 4: Average
Same as Exercise 3, but print both the sum and the average.

### Exercise 5: Subtracting from 501
Read non-zero integers until zero is typed. Subtract each one from a running score that
starts at 501. Print the final score.

### Exercise 6: "Stop"
Repeatedly read and print lines typed on the keyboard. Stop — without printing it — when
the user types the line `"stop"`.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    while (line != "stop") {
        std::cout << line << std::endl;
        std::getline(std::cin, line);
    }
    return 0;
}
```

### Exercise 7: Rectangle of coordinates
Input two positive integers `m` and `n`. Print an `m` by `n` grid of coordinates:
```
(1,1) (1,2) (1,3) (1,4)
(2,1) (2,2) (2,3) (2,4)
(3,1) (3,2) (3,3) (3,4)
```

### Exercise 8: Addition square
Print an addition table for 1–10, where row `i`, column `j` shows `i + j`:
```
    1  2  3  4  5  6  7  8  9 10
 1  2  3  4  5  6  7  8  9 10 11
 2  3  4  5  6  7  8  9 10 11 12
...
```

---

## Exam Style Question

**a.** [6 marks] Write a `while` loop fragment that does exactly the same thing, in all
circumstances, as the following `for` loop. Justify the equivalence.
```cpp
for (int i = 1; i < 4; i++) {
    std::cout << i << std::endl;
}
```

**b.** [9 marks] Trace this fragment, showing the value of every variable at each step:
```cpp
int t = 50;
int c = 5;
while (c <= 10) {
    t = t - c;
    c = c + 2;
}
t = t + 4;
```

**c.** [10 marks] Write a program that uses a `while` loop to simulate a dice game. The
person throws a real dice and types in the number. They aim for the highest score by
repeatedly throwing. If they roll a six, their score resets to 0 and the game ends; if
they choose to stop first, their score is the sum of all their throws.

Example run:
```
Would you like to throw? y
What number did you throw? 4
Your total is 4.

Would you like to throw? y
What number did you throw? 2
Your total is 6.

Would you like to throw? n
You scored 6.
```
