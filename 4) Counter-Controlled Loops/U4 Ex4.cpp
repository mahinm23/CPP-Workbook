#include <iostream>
void looper(int n) {
    for (int i=0; i<=n; i++){
        std::cout << i << std::endl;
    }
}


int main() {
    int inp;
    std::cout << "Enter a number to loop until" << std::endl;
    std::cin >> inp;
    std::cout << " " << std::endl;
    looper(inp);

    return 0;
}
