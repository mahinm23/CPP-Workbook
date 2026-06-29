#include <iostream>

void triangle(int n) {
    for (int i=0; i<=n; i++) {
        std::string str;
        for (int j=0; j<=i; j++) {
            str = str + std::string(" * ");
        }
        std::cout << str << std::endl;
    }
}

int main() {
    int inp;
    std::cout << "Enter your triangle size" << std::endl;
    std::cin >> inp;
    triangle(inp);

    return 0;
}