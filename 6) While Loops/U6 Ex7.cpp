#include <iostream>

void rectangle(int m, int n) {
    for (int i=1; i<=m; i++) {
        int j = 1;
       while (j<=n) {
        std::cout << "(" << i << "," << j << ") ";
        j = j+1;
       } 
       std::cout << std::endl;
    }   
}

int main() {
    int a;
    int b;

    std::cout << "Enter num 1" << std::endl;
    std::cin >> a;
    std::cout << "Enter num 2" << std::endl;
    std::cin >> b;

    rectangle(a, b);

    return 0;
}