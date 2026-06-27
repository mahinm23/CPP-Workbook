#include <iostream>

int main() {
    int response;
    std::cout << "Please enter a month" << std::endl;
    std::cin >> response;

    if (response == 2) {
        std::cout << 28 << std::endl;
    } else if (response == 4 | response == 6 | response == 9 | response == 11) {
        std::cout << 30 << std::endl;
    } else {
        std::cout << 31 << std::endl;
    }
    return 0;
}

// 28 feb
// 30 days april june sept november
// 4 6 9 11
// 31