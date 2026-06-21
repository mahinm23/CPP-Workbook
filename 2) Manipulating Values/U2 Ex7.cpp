#include <iostream>

float bonus(float total) {
    float share = total / 5;
    return share;
}

int main() {
    float total_bonus;

    std::cout << "Enter the company total bonus" << std::endl;
    std::cin >> total_bonus;
    std::cout << bonus(total_bonus) << std::endl;

    return 0;
}