#include <iostream>

int main() {

    int num1;
    int num2;
    int num3;
    std::cout << "Enter a number" << std::endl;
    std::cin >> num1;
    std::cout << "Enter another number" << std::endl;
    std::cin >> num2;
    std::cout << "Enter one last number" << std::endl;
    std::cin >> num3;
    if (num1 > num2) {
        if (num1 > num3) {
            std::cout << num1 << " - your first number was larger" << std::endl;
        } else {
            std::cout << num3 << " - the last number was the largest" << std::endl;
        }
    } else if (num1 < num2) {
        if (num2 > num3) {
            std::cout << num2 << " - your second number was larger" << std::endl;
        } else {
            std::cout << num3 << " - the last number was the largest" << std::endl;
        }
    } else {
        if (num1 > num3) {
            std::cout << num1 << " Num 1 and 2 are equal and larger than num 3" << std::endl;
        } else {
            std::cout << "They are equal" << std::endl;
        }
    }
}