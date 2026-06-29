#include <iostream>

void printer(int n) { 
    for (int i=0; i<=n; i++) {
        std::string str;
        for (int j=0; j<=n; j++){
            str = str + std::string(" P ");
        }
        std::cout << str << std::endl;
    }
}

int main() {
    int inp;
    std::cout << "What size square do you want to print" << std::endl;
    std::cin >> inp;
    printer(inp);

    return 0;
}