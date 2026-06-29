#include <iostream>

void adder(int n) {
    int sum = 0;
    for (int i=0; i<=n; i++){
        sum = sum + i;
        std::cout << "Current Sum " << sum << std::endl;
    }
    std::cout << "Final Sum " << sum << std::endl;
}

int main() {
    int inp;
    std::cout << "What number do you want to sum until?" << std::endl;
    std::cin >> inp;
    adder(inp);

    return 0;
}