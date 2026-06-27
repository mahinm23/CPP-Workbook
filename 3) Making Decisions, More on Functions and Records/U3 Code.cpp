#include <iostream>

int main() {

    int choice;
    std::cout << "Enter 1 or 2" << std::endl;
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "You chose 1" << std::endl;
    } else if (choice == 2) {
        std::cout << "You chose 2" << std::endl;
    } else {
        std::cout << "Invalid choice" << std::endl;
    }


}