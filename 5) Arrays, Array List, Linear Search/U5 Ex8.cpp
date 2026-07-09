#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

const int SIZE = 20;

void fillRandom(int arr[], int size) {
    // YOUR CODE — use rand() % 100 + 1
    for (int i=0; i<size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

int sumArray(int arr[], int size) {
    // YOUR CODE
    int sum = 0;
    for (int i=0; i<size; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

int countLessThan(int arr[], int size, int threshold) {
    // YOUR CODE
    int count = 0;
    for (int i=0; i<size; i++) {
        if (arr[i] < threshold) {
            count = count + 1;
        }
    }
    return count;

}

void runningTotals(int a[], int b[], int size) {
    // YOUR CODE — b[i] = a[0] + ... + a[i]
    b[0] = a[0];
    for (int i=1; i<size; i++) {
        b[i] = a[i] + b[i-1];
        std::cout << "Running Total: " << b[i] << std::endl;
    }
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