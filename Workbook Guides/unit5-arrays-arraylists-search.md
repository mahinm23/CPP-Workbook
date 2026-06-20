---
title: Unit 5 — Arrays, Array Lists & Linear Search (C++)
date: 18-06-2026
tags: [cpp, unit5, arrays, vectors, search]
status: active
---

# Unit 5: Arrays, Array Lists and Linear Search

## Learning Outcomes
- Read, write and debug programs that process bulk data using arrays
- Read, write and debug programs that search arrays for information
- Explain how arrays (and vectors) are declared and used
- Trace the execution of programs containing arrays

---

## Core Concept: Why Arrays?

Without arrays you'd need one variable per piece of data — useless for 200 students
or 1,000,000 readings. An array is a sequence of values, **all the same type**,
indexed by position starting at 0.

```
[10][11][12][13]
  0   1   2   3
```

---

## Java vs C++: Arrays and "Array Lists"

| Java | C++ | Notes |
|------|-----|-------|
| `int[] points = new int[10];` | `int points[10];` | C++ stack array, fixed size |
| `points.length` | `10` (you must track it) or `points.size()` for a vector | C++ stack arrays have no `.length` |
| `ArrayList<String> names = new ArrayList<>();` | `std::vector<std::string> names;` | Both grow dynamically |
| `names.add("x")` | `names.push_back("x");` | Append |
| `names.get(i)` | `names[i]` or `names.at(i)` | Access |
| `names.set(i, "y")` | `names[i] = "y";` | Update |
| `names.remove(i)` | `names.erase(names.begin() + i);` | Remove |
| `names.size()` | `names.size()` | Same name, lucky |
| `names.clear()` | `names.clear()` | Same |

**This module's style guide says prefer plain arrays over ArrayLists in assessed work** —
the C++ equivalent of that advice is: use `std::array`/raw arrays when the size is fixed
and known, use `std::vector` when it needs to grow. For these exercises default to plain
arrays unless a vector is clearly needed.

---

## C++ Syntax Reference

### Declaring and filling an array
```cpp
int points[10];                 // uninitialized, fixed size 10
for (int i = 0; i < 10; i++) {
    points[i] = 0;
}
```

### Length of an array
C++ stack arrays don't carry their length around like Java's `.length`. Track it yourself:
```cpp
const int SIZE = 10;
int points[SIZE];
// loop using SIZE, not a magic number
for (int i = 0; i < SIZE; i++) { ... }
```
Indexes run `0` to `SIZE - 1`. Going out of bounds is **undefined behaviour** in C++ —
unlike Java, it won't throw a clean exception; it may silently corrupt memory or crash.

### std::vector — the ArrayList equivalent
```cpp
#include <vector>

std::vector<std::string> medalists;
medalists.push_back("Sarah Storey");
medalists.push_back("Kadeena Cox");
medalists.push_back("Darren Kenny");

for (int i = 0; i < medalists.size(); i++) {
    std::cout << medalists[i] << std::endl;
}

medalists[2] = "David Weir";   // set
medalists.erase(medalists.begin() + 1); // remove index 1
medalists.clear();             // remove everything
```

### Printing every Nth element
```cpp
for (int i = 0; i < SIZE; i += 2) {
    std::cout << points[i] << std::endl;
}
```

### Lookup tables
A lookup table trades time for space: precompute once, then look up instead of recalculating.

---

## Worked Example: Lookup Cube (from workbook, translated to C++)

```cpp
#include <iostream>

const int SIZE = 10;

void createLookup(int lookup[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        lookup[i] = i * i * i;
    }
}

void useLookup(int lookup[SIZE]) {
    int query;
    std::cout << "Give me a number to cube quickly: ";
    std::cin >> query;
    if (query >= 0 && query < SIZE) {
        std::cout << query << " cubed is " << lookup[query] << std::endl;
    } else {
        std::cout << "Out of range (0-" << SIZE - 1 << ")" << std::endl;
    }
}

int main() {
    int lookup[SIZE];
    createLookup(lookup);
    useLookup(lookup);
    return 0;
}
```
Note the bounds check in `useLookup` — the original Java version crashes
(`ArrayIndexOutOfBoundsException`) if you ask for a value off the end of the array.
C++ won't even throw an exception; it will just read garbage memory or crash harder.
**Always validate array indices before using them.**

---

## Worked Example: Linear Search (and the classic off-by-one bug)

The workbook flags a common mistake: printing "Not in array" *inside* the loop on every
non-match, instead of only once at the end.

```cpp
// BUGGY version — prints "Not in array" on every miss before finding it
int a[] = {1, 2, 3, 4, 5};
int searchkey = 3;
for (int i = 0; i < 5; i++) {
    if (searchkey == a[i]) {
        std::cout << "Found" << std::endl;
        break;
    } else {
        std::cout << "Not in array" << std::endl;   // wrong — fires every non-match
    }
}
```

```cpp
// FIXED version — use a flag, only report failure after the whole array is checked
int a[] = {1, 2, 3, 4, 5};
int searchkey = 3;
bool found = false;
for (int i = 0; i < 5; i++) {
    if (searchkey == a[i]) {
        std::cout << "Found" << std::endl;
        found = true;
        break;
    }
}
if (!found) {
    std::cout << "Not in array" << std::endl;
}
```
You can't declare "not in the array" until you've checked the **whole** array —
that's why the failure message goes outside the loop.

### Linear search as a reusable function
```cpp
int search(int a[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (a[i] == key) {
            return i;      // the early return acts like break
        }
    }
    return -1;             // NOT FOUND — outside the loop
}
```

---

## Exercises

### Exercise 1: Times table
Initialise an array so position `i` holds `2 * i` (the 2 times table: position 2 holds 4, etc).

### Exercise 2: Read names into an array
Fill a `std::string` array of size 10 by asking the user to type in 10 names.

### Exercise 3: Print an array
Write a function `printArray(int arr[], int size)` that prints every entry.

### Exercise 4: Fill and print
Read 10 integers from the keyboard into an array, then print them all back.
(Two loops — one to read, one to print.)

### Exercise 5: Reverse
Read 10 integers into an array, then print them out in reverse order.

### Exercise 6: More than 5
Read 12 numbers into an array, print them all, then print only the ones greater than 5.

### Exercise 7: Pretty-print
Print an array as a table with the index above the value:
```
0   1   2   3   4   5   6   7   8   9
1   8  10   7   4 112  43 144  18  11
```
Then try a fancier version with a header row and a separator line of dashes.

### Exercise 8: Random array stats
Fill an array `A` of size 20 with random ints 1–100. Then:
- (a) Sum all elements
- (b) Count elements less than 10
- (c) Build a new array `B` where `B[i] = A[0] + A[1] + ... + A[i]` (running total)

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

const int SIZE = 20;

void fillRandom(int arr[], int size) {
    // YOUR CODE — use rand() % 100 + 1
}

int sumArray(int arr[], int size) {
    // YOUR CODE
}

int countLessThan(int arr[], int size, int threshold) {
    // YOUR CODE
}

void runningTotals(int a[], int b[], int size) {
    // YOUR CODE — b[i] = a[0] + ... + a[i]
}

int main() {
    srand(time(0));
    int a[SIZE], b[SIZE];
    fillRandom(a, SIZE);
    std::cout << "Sum: " << sumArray(a, SIZE) << std::endl;
    std::cout << "Count < 10: " << countLessThan(a, SIZE, 10) << std::endl;
    runningTotals(a, b, SIZE);
    return 0;
}
```

### Exercise 9: Search for a given number/string
Fill an array with 20 random ints, print it, then search it for an integer typed by the user.
Repeat for an array of strings.

### Exercise 10: Copy and double
Read integers until a zero is read, storing them in array `A`. Copy them into array `B`,
doubling each value (`B[i] = A[i] * 2`). Print `B`.

### Exercise 11: Find the maximum
Fill an array of 20 random ints. Scan it to find the largest value **and its index**.
Hint: keep a running "best so far" and compare each new value against it.

### Exercise 12: Subset test
Fill two arrays `A` and `B` with 20 random ints in range 1–10. Test whether every number
in `B` also occurs somewhere in `A` (repeated linear search).

### Exercise 13: Sieve of Eratosthenes
Generate all primes less than `n` using a `bool` array of size `n`, all initially `false`
("not crossed off"). For each `k` not yet crossed off, cross off all multiples of `k`.
The numbers never crossed off are prime. Print the primes and the count.
Bonus: stop the outer loop at `sqrt(n)` instead of `n` — explain why that's still correct.

```cpp
#include <iostream>
#include <cmath>

void sieve(bool crossedOff[], int n) {
    for (int i = 0; i <= n; i++) crossedOff[i] = false;
    // YOUR CODE — implement the sieve
}

int main() {
    int n = 30;
    bool crossedOff[31];
    sieve(crossedOff, n);
    for (int i = 2; i <= n; i++) {
        if (!crossedOff[i]) std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

---

## Exam Style Question: Arrays

**a.** [6 marks] The following fragments contain bugs. Identify and correct them.
```cpp
// i)
// increment position 5 of array a
a(5) = a(5) + 1;

// ii)
// print all elements of an array of size 10
for (int i = 0; i <= 10; i++) {
    std::cout << a[i] << std::endl;
}

// iii)
// declare an integer array with 4 elements
int a[];
```

**b.** [9 marks] Dry run this fragment, showing the array contents at each step:
```cpp
int a[6];
for (int i = 0; i <= 4; i++) {
    a[i] = i;
}
for (int j = 0; j <= 4; j++) {
    a[j + 1] = a[j + 1] + a[j];
}
```

**c.** [10 marks] Write a program that reads 20 integers from the keyboard, then searches
the array and prints the position of **every** place the target integer was found
(not just the first).
