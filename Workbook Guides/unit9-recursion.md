---
title: Unit 9 — Recursion & Divide and Conquer (C++)
date: 18-06-2026
tags: [cpp, unit9, recursion, algorithms]
status: active
---

# Unit 9: Recursion & Divide and Conquer

## Learning Outcomes
- Read, write and debug programs using recursion
- Implement divide and conquer algorithms
- Explain base case and step case
- Implement binary search

---

## Core Concept: Recursion

A function is **recursive** if it calls itself.
It needs two parts:
- **Base case:** the simple case that terminates (no recursive call)
- **Step case:** reduces the problem and calls itself with a smaller input

If you forget the base case → infinite loop → stack overflow.

---

## C++ Syntax Reference (new for this unit)

### User input
```cpp
#include <iostream>
int n;
std::cin >> n;
std::string s;
std::getline(std::cin, s);
```

### Conditional expression (same as Java)
```cpp
if (n == 0) return 0;
else return n + sumToN(n - 1);
```

### Function prototype (declare before use)
```cpp
// If function A calls function B, and B is defined after A,
// declare B before A:
int sumToN(int n);   // prototype

int main() {
    std::cout << sumToN(5) << std::endl;
    return 0;
}

int sumToN(int n) {
    if (n == 0) return 0;
    else return n + sumToN(n - 1);
}
```

---

## sumToN: Two Versions

### Iterative (while loop — from Unit 6)
```cpp
int sumToN_iterative(int n) {
    int sum = 0;
    while (n != 0) {
        sum = n + sum;
        n = n - 1;
    }
    return sum;
}
```

### Recursive
```cpp
int sumToN(int n) {
    if (n == 0)              // base case
        return 0;
    else
        return n + sumToN(n - 1);   // step case
}
```

**Trace for n=3:**
```
sumToN(3)
  = 3 + sumToN(2)
        = 2 + sumToN(1)
              = 1 + sumToN(0)
                    = 0         ← base case
              = 1 + 0 = 1
        = 2 + 1 = 3
  = 3 + 3 = 6
```
Each call waits on the stack until the base case returns. Then it unwinds.

---

## Tail Recursion (BAD — avoid)

The last thing the function does is the recursive call. Wastes stack space.

```cpp
// BAD — tail recursion
void printCountDown(int n) {
    if (n == 0) return;
    std::cout << n << std::endl;
    printCountDown(n - 1);  // last thing — tail recursive
}
// Use a loop instead:
void printCountDown_better(int n) {
    while (n > 0) {
        std::cout << n << std::endl;
        n--;
    }
}
```

**sumToN is NOT tail recursive** — it still has work to do after the call returns (`n + ...`).

---

## Head Recursion

The recursive call happens FIRST, then the work:

```cpp
void print0toN(int n) {
    if (n == -1) return;
    print0toN(n - 1);        // recurse first
    std::cout << n << std::endl;  // then print — prints in ascending order
}
```

---

## Divide and Conquer

Pattern:
```
solve(problem):
  if trivial: return solution
  else:
    split into smaller problems
    solve each smaller problem (recursively)
    combine results
```

---

## Binary Search (Divide and Conquer)

Array must be sorted first. Repeatedly halve the search space.

```cpp
// Returns index of target in arr[from..to], or -1 if not found
int binarySearch(int target, int arr[], int from, int to) {
    if (from > to) return -1;             // base case: not found

    int mid = (from + to) / 2;

    if (arr[mid] == target)
        return mid;                        // base case: found
    else if (arr[mid] < target)
        return binarySearch(target, arr, mid + 1, to);   // right half
    else
        return binarySearch(target, arr, from, mid - 1); // left half
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int result = binarySearch(7, arr, 0, 6);
    if (result == -1)
        std::cout << "Not found" << std::endl;
    else
        std::cout << "Found at index " << result << std::endl;
    return 0;
}
```

Note: binary search is technically tail recursive (the recursive call IS the return).
For large arrays use an iterative version, but recursive is fine for learning.

---

## Towers of Hanoi

```cpp
#include <iostream>

// Move n discs from pillar 'from' to pillar 'to' using 'via' as spare
void hanoi(int n, char from, char to, char via) {
    if (n == 1) {
        std::cout << "Move disc 1 from " << from << " to " << to << std::endl;
        return;
    }
    hanoi(n - 1, from, via, to);   // move top n-1 to spare
    std::cout << "Move disc " << n << " from " << from << " to " << to << std::endl;
    hanoi(n - 1, via, to, from);   // move n-1 from spare to target
}

int main() {
    hanoi(3, 'A', 'C', 'B');
    return 0;
}
```

---

## Exercises

### Exercise 1: sumToN
Write `int sumToN(int n)` recursively. Test for n = 0, 1, 5, 10.

### Exercise 2: multiply first n numbers (factorial)
```
factorial(0) = 1      ← base case
factorial(n) = n * factorial(n-1)
```
Write it. Test: `factorial(5)` should return 120.

### Exercise 3: Mathematical functions — implement all four
```cpp
// Factorial: n=0 → 1, else n * factorial(n-1)
int factorial(int n);

// Fibonacci: n=0 or n=1 → 1, else fibonacci(n-1) + fibonacci(n-2)
int fibonacci(int n);

// Exponential: exp(m, 0) = 1, exp(m, n) = m * exp(m, n-1)
int exponential(int m, int n);

// GCD (Euclid): gcd(0,n) = 0, gcd(m,n) = m if m==n,
//               gcd(m,n) = gcd(n,m) if n<m, else gcd(m, n-m)
int gcd(int m, int n);
```

### Exercise 4: Binary search
Write `int search(int target, int arr[], int from, int to)`.
Test it with:
- An array of sorted integers, searching for values that ARE in the array
- Searching for a value that is NOT in the array (should return -1)

### Exercise 5: Towers of Hanoi
Write the Hanoi function above from scratch (don't copy — understand it first).
Run for n=1, n=2, n=3. How many moves for each? What's the pattern?

### Exercise 6: Recursive counter (tracing exercise)
Write this function and run it for `loop(5)`. Trace the output on paper first:
```cpp
void loop(int n) {
    std::cout << "Entering " << n << std::endl;
    if (n == 0) {
        std::cout << "Base case" << std::endl;
    } else {
        std::cout << "Working " << n << std::endl;
        loop(n - 1);
    }
    std::cout << "Leaving " << n << std::endl;
}
```
Note: "Leaving" prints AFTER the recursive call returns — that's the unwinding.

---

## Exam Style Question

**a.** Explain what is meant by (i) a base case (ii) a step case in recursion. [6 marks]

**b.** The following function is recursive:
```cpp
int f(int n) {
    if (n == 0) return 1;
    else return n * f(n - 2);
}
```
(i) Write an equivalent version using a loop instead of recursion.
(ii) Explain how this function could fail to terminate. [9 marks]

**c.** Discuss: "Recursion is not necessary — every recursive program can be written with loops instead." Is this true? What are the trade-offs? [10 marks]
