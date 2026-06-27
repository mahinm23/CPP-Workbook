#include <iostream>

int main() {

    int choice;
    std::cout << "How many beans make five?" << std::endl;
    std::cin >> choice;
    if (choice == 5) {
        std::cout << "Correct" << std::endl;
    } else if (choice == 4 | choice == 6) {
        std::cout << "About correct" << std::endl;
    } else {
        std::cout << "Wrong" << std::endl;
    }

}