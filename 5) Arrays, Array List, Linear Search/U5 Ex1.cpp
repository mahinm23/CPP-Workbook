#include <iostream>

int main() {
    int arr[12];
    for (int i=0; i<=12; i++) {
        arr[i] = i * 2;
    }

    for (int i=0; i<=12; i++) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}