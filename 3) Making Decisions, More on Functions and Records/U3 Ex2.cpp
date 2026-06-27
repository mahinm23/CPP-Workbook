#include <iostream>

int main() {

    int num1;
    int num2;
    std::cout << "Enter a number" << std::endl;
    std::cin >> num1;
    std::cout << "Enter another number" << std::endl;
    std::cin >> num2;
    if (num1 > num2) {
        std::cout << num1 << " - your first number was larger" << std::endl;
    } else if (num1 < num2) {
        std::cout << num2 << " - your second number was larger" << std::endl;
    } else {
        std::cout << "They are equal" << std::endl;
    }
}