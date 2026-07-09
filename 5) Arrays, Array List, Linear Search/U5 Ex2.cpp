#include <iostream>

int main() {
    const int SIZE = 4;
    std::string names[SIZE];
    for (int i=0; i<SIZE; i++) {
        std::cout << "Enter a name" << std::endl;
        std::getline(std::cin, names[i]);
    }

    std::cout << "" << std::endl;

    for (int i=0; i<SIZE; i++) {
        std::cout << names[i] << std::endl;
    }

    return 0;
}