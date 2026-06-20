---
title: Unit 8 — References, Heap & Stack (C++)
date: 18-06-2026
tags: [cpp, unit8, pointers, references]
status: active
---

# Unit 8: References, Heap & Stack

## Learning Outcomes
- Compare how integers vs arrays (and other complex types) are stored
- Explain stack vs heap
- Explain how arrays are passed to functions
- Explain pass by value vs pass by reference

---

## Core Concept: Stack vs Heap

**The Stack** holds:
- Local variables (int, char, double, bool)
- Function parameters
- Created automatically when a block starts, freed when it ends

**The Heap** holds:
- Dynamically allocated memory (`new`)
- Lives until you explicitly `delete` it (or program ends)
- Accessed via a **pointer**

```
Stack              Heap
--------           ----------
n  | 21  |         [1][2][3][4]   ← actual array data
pi | 3.14 |    ↗
a  |  •──────────      ← 'a' holds an ADDRESS (pointer)
```

---

## Java vs C++: The Key Difference

In **Java**, all arrays are heap objects. You have no choice.
In **C++**, you choose:

```cpp
// Stack array — fixed size, no new, automatically freed
int a[5];           // 5 ints on the stack

// Heap array — dynamic, must delete[] when done
int* a = new int[5];   // pointer on stack, array on heap
delete[] a;            // free heap memory when done
```

**For exercises on this flight: use stack arrays (`int a[5]`) unless told otherwise.**
They're simpler — no memory management needed.

---

## C++ Syntax Reference

### Basic types
```cpp
int x = 5;
double pi = 3.14;
char c = 'A';
bool b = true;
```

### Arrays (stack)
```cpp
int arr[5];                    // uninitialized
int arr[5] = {0, 0, 0, 0, 0}; // initialized to zeros
int arr[] = {1, 2, 3, 4};     // size inferred (4 elements)
arr[0] = 10;                   // access element
```

### Printing (no System.out.println)
```cpp
#include <iostream>
std::cout << "Hello" << std::endl;
std::cout << x << std::endl;
std::cout << "Value: " << x << " and " << y << std::endl;
```

### Functions (no public static)
```cpp
// Void function (procedure)
void printMessage() {
    std::cout << "Hello" << std::endl;
}

// Function returning int
int add(int a, int b) {
    return a + b;
}

// Main
int main() {
    printMessage();
    std::cout << add(3, 4) << std::endl;
    return 0;
}
```

### For loop (identical to Java)
```cpp
for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << std::endl;
}
```

---

## Pass by Value vs Pass by Reference

### Pass by VALUE (copy — changes don't persist)
```cpp
void intInc(int x) {
    x++;   // x is a copy — caller's variable unchanged
}

int main() {
    int n = 1;
    intInc(n);
    std::cout << n << std::endl;  // prints 1, not 2
    return 0;
}
```

### Pass by POINTER (array — changes persist)
```cpp
// Arrays decay to pointers — mutations affect the original
void arrayInc(int arr[], int index) {
    arr[index]++;   // modifies the actual array on heap/stack
}
// OR explicitly:
void arrayInc(int* arr, int index) {
    arr[index]++;
}

int main() {
    int a[1] = {1};
    arrayInc(a, 0);
    std::cout << a[0] << std::endl;  // prints 2
    return 0;
}
```

### Pass by REFERENCE (C++ only — not in Java)
C++ lets you pass ANY variable by reference with `&`:
```cpp
void increment(int& x) {
    x++;   // x is an alias for the caller's variable — it DOES change
}

int main() {
    int n = 1;
    increment(n);
    std::cout << n << std::endl;  // prints 2
    return 0;
}
```

### Summary table
| What's passed | Java | C++ | Mutation persists? |
|--------------|------|-----|--------------------|
| int | by value (copy) | `int x` by value | No |
| int (modified) | not possible | `int& x` by reference | Yes |
| array | by reference (automatic) | `int arr[]` or `int* arr` | Yes |

---

## Array swap (works because array is passed by pointer)
```cpp
void arraySwap(int arr[], int x, int y) {
    int tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}
```

This DOES swap. Compare with:
```cpp
void intSwap(int x, int y) {
    int tmp = x;
    x = y;
    y = tmp;
}
// This does NOTHING — x and y are copies
```

---

## Worked Example: Queue (from workbook, translated to C++)

```cpp
#include <iostream>
#include <string>

const int MAX = 10;

struct Queue {
    std::string entries[MAX];
    int numberQueueing;
};

Queue createEmptyQueue() {
    Queue q;
    q.numberQueueing = 0;
    return q;
}

void joinQueue(Queue& q, std::string newEntry) {
    if (q.numberQueueing < MAX) {
        q.entries[q.numberQueueing] = newEntry;
        q.numberQueueing++;
    }
}

std::string leaveQueue(Queue& q) {
    std::string front = q.entries[0];
    if (q.numberQueueing != 0) {
        for (int i = 0; i < q.numberQueueing; i++) {
            q.entries[i] = q.entries[i + 1];
        }
        q.numberQueueing--;
    }
    return front;
}

std::string firstInQueue(Queue& q) {
    return q.entries[0];
}

int main() {
    Queue q = createEmptyQueue();
    joinQueue(q, "Alistair Brownlee");
    std::cout << firstInQueue(q) << std::endl;
    joinQueue(q, "Mo Farah");
    std::cout << leaveQueue(q) << std::endl;
    std::cout << leaveQueue(q) << std::endl;
    return 0;
}
```

Note: `Queue& q` passes by reference so `joinQueue` actually modifies the queue.
In Java this happened automatically for objects. In C++ you must write `&`.

---

## Exercises

### Exercise 1: Trace (dry run — don't compile first, predict output)
```cpp
int a = 1;
int b = 2;
b = a;
std::cout << a << std::endl;  // ?
std::cout << b << std::endl;  // ?
a = 5;
std::cout << a << std::endl;  // ?
std::cout << b << std::endl;  // ?
```
Answer: 1, 1, 5, 1 — integers are copied, b doesn't follow a.

### Exercise 2: Trace arrays
```cpp
int a[] = {1, 2};
int b[] = {3, 4};
// In C++, you CANNOT do b = a on stack arrays
// On heap (pointers): int* b = a; then b[0] = 5 ALSO changes a[0]
// Concept: pointer assignment copies address, not data
```

### Exercise 3: Fill array
Write a function `fillEven(int arr[], int size)` that fills `arr` with even numbers starting from 0 (0, 2, 4, 6...).
Write `main` to test it with an array of size 5 and print all elements.

```cpp
#include <iostream>

void fillEven(int arr[], int size) {
    // YOUR CODE HERE
    // Hint: arr[i] = i * 2;
}

int main() {
    int a[5];
    fillEven(a, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << a[i] << std::endl;
    }
    return 0;
}
```

### Exercise 4: Double array
Write `doubleAll(int arr[], int size)` that doubles every element in-place.
Test: `{1, 2, 3}` → `{2, 4, 6}`

### Exercise 5: Arrays vs integers
Write a function `zeroOut(int arr[], int size, int x)` that:
- Sets every element of `arr` to 0
- Sets `x` to 0

In `main`, create an array `{1,2,3}` and `int n = 5`. Call `zeroOut`. Print both.
Show that `arr` is zeroed but `n` is unchanged. Then rewrite using `int& x` and show `n` IS changed.

### Exercise 6: Phone book (main exercise)
Write a program that:
1. Asks user how many people to enter (up to 20)
2. Reads that many name/number pairs into two parallel arrays
3. Loops asking the user for a name to search
4. Searches the names array, prints the matching number (or "Not found")
5. Stops when user enters "quit"

```cpp
#include <iostream>
#include <string>

const int MAX_ENTRIES = 20;

void inputDetails(std::string names[], std::string numbers[], int& count) {
    // YOUR CODE
}

void search(std::string names[], std::string numbers[], int count, std::string target) {
    // YOUR CODE — linear search
}

int main() {
    std::string names[MAX_ENTRIES];
    std::string numbers[MAX_ENTRIES];
    int count = 0;
    inputDetails(names, numbers, count);
    std::string query;
    while (true) {
        std::cout << "Enter name to search (or quit): ";
        std::getline(std::cin, query);
        if (query == "quit") break;
        search(names, numbers, count, query);
    }
    return 0;
}
```

---

## Exam Style Question

**a.** Explain what is meant by the stack and the heap in C++. [6 marks]

**b.** Compare passing an array vs passing an int to a function. What is different about what happens when the function modifies the parameter? Illustrate with a short code example. [9 marks]

**c.** Write a program that allows a user to input N names and phone numbers. Once entered, allow the user to search for a number by name. Use separate functions for input and search; declare arrays in main and pass them as parameters. [10 marks]
