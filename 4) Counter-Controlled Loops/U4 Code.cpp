#include <iostream>

int main() {
    for (int i=1; i<=5; i++) {
        std::cout << i << ". Hello" << std::endl;
    }

    for (int i=1; i<=10; i++) {
        for (int j=i; i<=10; i++) {
            std::cout << "0" << std::endl;
        }
    }

    return 0;
}
