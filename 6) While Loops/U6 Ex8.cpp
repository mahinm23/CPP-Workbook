#include <iostream>

void grid() {
    int i = 0;
    std::cout << " ";
    while (i<=10) {
        int j = 0;
        while (j<=10) {
            std::cout << i+j << " ";
            j = j+1;
        }
        std::cout << std::endl;
        i = i + 1;
    }
}

int main() {
    grid();
    return 0;
}