#include <iostream>
void display(int n) {
    std::cout << "Timestable for " << n << std::endl;
    for (int i=0; i<=12; i++) {
        std::cout << i << " x " << n << " = " << i*n << std::endl;
    }
}

int main() {
    int inp;
    std::cout << "What timestable would you like to see?" << std::endl;
    std::cin >> inp;
    display(inp);

    return 0;
}