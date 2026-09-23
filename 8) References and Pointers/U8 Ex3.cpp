#include <iostream>

void fillEven(int arr[], int size) {
    // YOUR CODE HERE
    // Hint: arr[i] = i * 2;

    // Fill arr with even numbers from 0
    for (int i = 0; i<size; i++){
        arr[i] = i*2;
    }
}

int main() {
    int a[5];
    fillEven(a, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << a[i] << std::endl;
    }
    return 0;
}
