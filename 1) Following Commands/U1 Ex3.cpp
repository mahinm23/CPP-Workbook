#include <iostream>

std::string getInfo() {
    std::string info;
    std::getline(std::cin, info);
    return info;
}

void address() {
    std::cout << "Whats your name?" << std::endl;
    std::string name = getInfo();

    std::cout << "Whats your street address?" << std::endl;
    std::string add = getInfo();

    std::cout << "Lastly, whats your postcode?" << std::endl;
    std::string post = getInfo();

    std::cout << "This is your address label" << std::endl;
    std::cout << name << std::endl;
    std::cout << add << std::endl;
    std::cout << post << std::endl;
}

int main() {
    address();
    return 0;
}