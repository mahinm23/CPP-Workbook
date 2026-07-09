#include <iostream>

int main() {
    const int SIZE = 5;
    int arr[SIZE];
    std::cout << "Enter numbers to fill the array" << std::endl;
    for (int i=0; i<SIZE; i++) {
        std::cout << "Number " << i << ": " << std::endl;
        std::cin >> arr[i];
    }

    std::cout << " " << std::endl;
    std::cout << "Numbers in reverse: ";
    for (int i=SIZE-1; i>=0; i--){
        std::cout <<  arr[i] << std::endl;
    }

    return 0;
}