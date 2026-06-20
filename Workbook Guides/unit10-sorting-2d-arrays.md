---
title: Unit 10 — Sorting & 2D Arrays (C++)
date: 18-06-2026
tags: [cpp, unit10, sorting, algorithms, arrays]
status: active
---

# Unit 10: Sorting & 2D Arrays

## Learning Outcomes
- Explain and implement different sorting algorithms
- Read, write and debug programs to sort arrays
- Declare and use multi-dimensional arrays
- Understand mergesort and quicksort (divide and conquer)

---

## C++ Syntax Reference (new for this unit)

### Random numbers
```cpp
#include <cstdlib>    // rand(), srand()
#include <ctime>      // time()

srand(time(0));       // seed with current time (once, at start of main)
int r = rand() % 100; // random int 0..99
```

### String comparison (for dictionary sorting)
```cpp
#include <string>
std::string a = "apple";
std::string b = "banana";
if (a < b) ...      // alphabetical — works directly with std::string
if (a.compare(b) < 0) ...  // returns negative if a comes before b
```

### 2D arrays
```cpp
int matrix[3][4];             // 3 rows, 4 columns
matrix[1][2] = 5;             // row 1, col 2
int rows = 3, cols = 4;
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
}
```

---

## Swap Helper (needed for all sort algorithms)

```cpp
void swap(int arr[], int x, int y) {
    int tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}
```

Works because arrays are passed by pointer — mutation persists.

---

## Bubble Sort: Three Versions

### Version 1: Naïve (always does n-1 passes)
```cpp
void naiveBubbleSort(int arr[], int length) {
    for (int pass = 1; pass <= length - 1; pass++) {
        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
            }
        }
    }
}
```

### Version 2: Improved (inner loop shrinks — no wasted comparisons)
```cpp
void bubbleSort(int arr[], int length) {
    for (int pass = 1; pass <= length - 1; pass++) {
        for (int i = 0; i < length - pass; i++) {   // shrinks by pass
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
            }
        }
    }
}
```

### Version 3: Early exit (stop if already sorted)
```cpp
void earlyExitBubbleSort(int arr[], int length) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
                sorted = false;   // found out-of-order pair, not sorted yet
            }
        }
    }
}
```

---

## Selection Sort (insertion sort variant)

Repeatedly find the minimum and place it at the front:

```cpp
void selectionSort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        // Find index of minimum in arr[i..length-1]
        int minIdx = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap minimum into position i
        swap(arr, i, minIdx);
    }
}
```

---

## Mergesort (Divide and Conquer)

Split array in half, recursively sort each half, merge the two sorted halves:

```cpp
// Merge arr[left..mid] and arr[mid+1..right] into arr
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];    // temporary arrays

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {             // base case: single element, already sorted
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Call like: mergeSort(arr, 0, length - 1);
```

---

## Quicksort (Divide and Conquer)

Pick a pivot, move smaller elements left, larger elements right, recurse:

```cpp
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // pivot is last element
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Call like: quickSort(arr, 0, length - 1);
```

---

## 2D Arrays / Matrices

```cpp
// Declare a 3x3 matrix
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Process every element
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
}

// Pass 2D array to function
void printMatrix(int arr[][4], int rows) {   // must specify column count
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 4; j++)
            std::cout << arr[i][j] << " ";
}
```

---

## Print Array Helper (useful for all exercises)

```cpp
void printArray(int arr[], int length) {
    std::cout << "[";
    for (int i = 0; i < length; i++) {
        std::cout << arr[i];
        if (i < length - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
```

---

## Exercises

### Exercise 1: Bubble sort descending
Write a program with an array of 20 random integers. Sort them in **descending** order using bubble sort. Print the array after every swap.

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int arr[], int x, int y) { /* as above */ }
void printArray(int arr[], int length) { /* as above */ }

void bubbleSortDesc(int arr[], int length) {
    // Change: swap when arr[i] < arr[i+1] for descending
    // YOUR CODE
}

int main() {
    srand(time(0));
    int arr[20];
    for (int i = 0; i < 20; i++) arr[i] = rand() % 100;

    std::cout << "Before: "; printArray(arr, 20);
    bubbleSortDesc(arr, 20);
    std::cout << "After: "; printArray(arr, 20);
    return 0;
}
```

### Exercise 2: Improved bubble sort
Modify the above so the inner loop shrinks by one each pass. Count comparisons and swaps, print the totals at the end.

### Exercise 3: Selection sort
Write `selectionSort` (as shown above). Test with a random array of 20 ints. Count comparisons and swaps — compare the count with bubble sort.

### Exercise 4: Binary search with sort
Write a program that:
1. Fills an array with 20 random integers
2. Sorts it (use any sort)
3. Searches for a user-specified value using binary search (from Unit 9)

### Exercise 5: Dictionary sort (sort strings)
```cpp
#include <iostream>
#include <string>

void sortStrings(std::string words[], int length) {
    // Use bubble sort — replace arr[i] > arr[i+1] with words[i] > words[i+1]
    // std::string supports < and > directly
}

int main() {
    std::string words[] = {"banana", "apple", "cherry", "date", "elderberry"};
    int length = 5;
    sortStrings(words, length);
    for (int i = 0; i < length; i++)
        std::cout << words[i] << std::endl;
    return 0;
}
```

### Exercise 6: Recursive mergesort
Write mergesort from scratch (use the template above as a guide). Test it. Then:
- Count comparisons and compare with bubble sort on the same data
- Try with already-sorted input — which algorithm is faster?

---

## Exam Style Question

**a.** The following algorithm sorts an array. Explain with simple changes how it can be improved, and justify your answer. [6 marks]
```cpp
for (int pass = 0; pass <= length - 2; pass++)
    for (int i = 0; i <= length - 2; i++)
        if (arr[i] < arr[i + 1])
            swap(arr, i, i + 1);
```

**b.** Compare and contrast: (i) bubble sort (ii) mergesort. Consider: time complexity, in-place vs extra memory, best/worst case. [9 marks]

**c.** Discuss: "Searching is faster if data is sorted." Is this always true? Under what conditions? [10 marks]
