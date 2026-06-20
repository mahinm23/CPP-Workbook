#include <iostream>

void storeHelloMessage() {
    std::string myWelcome = "Hi, there. This is Eddie your shipboard computer";
    std::cout << myWelcome << std::endl;
}

void otherMsg() {
    std::string myWelcome = "Go ahead punk, make my day";
    std::cout << myWelcome << std::endl;    
}

int main() {
    storeHelloMessage();
    otherMsg();
}