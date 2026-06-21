#include <iostream>

int main() {
    srand(time(0));
    int roll = rand() % 6 + 5;
    std::cout << roll << std::endl;

    return 0;
}