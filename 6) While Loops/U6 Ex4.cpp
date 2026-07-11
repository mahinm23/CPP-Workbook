#include <iostream>

int main() {
    int sum = 0;
    int inp;
    float average;
    int n = 0;
    while (inp != 0) {
        std::cout << "Enter a number" << std::endl;
        std::cin >> inp;
        sum = sum + inp;
        n = n + 1;
    }
    average = sum / (n-1);

    std::cout << "Sum " << sum << std::endl;
    std::cout << "Average " << average << std::endl;
    return 0;
}