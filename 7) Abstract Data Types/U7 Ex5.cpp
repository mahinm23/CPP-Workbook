#include <iostream>

void printChar(char c, int n){
    for (int i=0; i<=n; i++){
        std::cout << c << " ";
    }
    std::cout << std::endl;
}


int main() {
    char inp;
    int num;
    std::cout << "Enter a character" << std::endl;
    std::cin >> inp;
    std::cout << "How many times do you want to print it" << std::endl;
    std::cin >> num;

    printChar(inp, num);

    int height;
    int width;
    std::cout << " " << std::endl;
    std::cout << "How tall do you want the rectangle to be?" << std::endl;
    std::cin >> height;
    std::cout << "How wide do you want the rectangle to be?" << std::endl;
    std::cin >> width;
    for (int i=0; i<height; i++){
        printChar('*', width);
    }

    int a;
    int b;
    std::cout << " " << std::endl;
    std::cout << "How tall do you want the triangle to be?" << std::endl;
    std::cin >> a;
    std::cout << "How wide do you want the triangle to be?" << std::endl;
    std::cin >> b;
    for (int i=0; i<height; i++){
        printChar('*', width-1-i);
    }

    return 0;
}