#include <iostream>

int main() {
    int cost;
    int weight;

    std::cout << "What is the weight of your package?" << std::endl;
    std::cin >> weight;

    cost = 6;
    if (weight > 20) {
        std::cout << "Max Limit" << std::endl;
        return 0;
    } else if (weight > 5) {
        cost = cost + 3*(weight-5);
        weight = 5;
    }

    if (weight <= 5 | weight >1) {
        cost = cost + 4*(weight-1);
    } 

    std::cout << "The total cost is " << cost << std::endl;
    return 0;
}