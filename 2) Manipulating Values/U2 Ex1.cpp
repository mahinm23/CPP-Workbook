#include <iostream>

int getNum() {
    int num;
    std::cin >> num;
    return num;
}

void num() {
    std::cout << "Whats your number? ";
    int num = getNum();
    std::cout << num+1 << " is your number + 1" << std::endl;
}

int main() {
    num();
    return 0;
}