#include <iostream>

int main() {
    srand(time(0));
    int roll = rand() % 6 + 5;
    std::cout << roll << " Roll 1" << std::endl;
    std::cout << " " << std::endl;

    int roll2 = (rand() % 6)*2 + 1;
    std::cout << roll2 << " Roll 2" << std::endl;

    return 0;
}