#include <iostream>

int main() {

    int pence;
    int pounds;
    int remainder;
    std::string result;

    std::cout << "Enter your pence" << std::endl;
    std::cin >> pence;

    pounds = pence / 100;
    remainder = pence % 100;

    std::cout << pence << " -> " << "£" << pounds << "." << remainder << std::endl;

    return 0;
}