#include <iostream>

int main() {

    int year;
    std::cout << "Please enter a year" << std::endl;
    std::cin >> year;

    if (year % 4 == 0 && year % 100 != 0) {
        std::cout << "This is a leap year";
    } else {
        std::cout << "Not a leap year" << std::endl;
    }

    return 0;
}