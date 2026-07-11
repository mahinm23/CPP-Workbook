#include <iostream>

int main() {
    int sum = 0;
    int inp;
    while (inp != 0) {
        std::cout << "Enter a number" << std::endl;
        std::cin >> inp;
        sum = sum + inp;
    }

    std::cout << sum << std::endl;
    return 0;
}