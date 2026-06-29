#include <iostream>

void rectangle(int n, int m) {
    std::string str;
    for (int i=0; i<=n; i++) {
        std::string str;
        for (int j=0; j<=m; j++){
            str = str + std::string(" * ");
        }
        std::cout << str << std::endl;
    }
}

int main() {
    int m;
    int n;
    std::cout << "Enter first num" << std::endl;
    std::cin >> m;
    std::cout << "Enter second num" << std::endl;
    std::cin >> n;

    rectangle(m, n);

    return 0;
}

