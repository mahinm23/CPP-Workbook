#include <iostream>

int f2c(int f) {
    int c = (f-32)*5/9;
    return c;
}

int c2f(int c) {
    int f = (c *9 / 5)-32;
    return f;
}

int main() {
    std::cout << "Enter your farenheit to convert to celsius" << std::endl;
    int f; 
    std::cin >> f;
    int c = f2c(c);
    std::cout << f << "f in celsius is " << c << "C"<< std::endl;

    int c1;
    int f1;
    std::cout << "Enter c to convert to f" << std::endl;
    std::cin >> c1;
    std::cout << c1 << " in farenheit is " << f1 << "f" << std::endl;
    return 0;
}