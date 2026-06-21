#include <iostream>

int main() {
    srand(time(0));
    std::cout << rand() % 12 + 1 << std::endl;
    return 0;
}