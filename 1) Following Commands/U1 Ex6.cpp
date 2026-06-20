#include <iostream>

std::string getStr(){
    std::string string;
    std::getline(std::cin, string);
    return string;
}

void concatStr() {
    std::cout << "Enter your first string" << std::endl;
    std::string str1 = getStr();
    std::cout << "Enter your second string" << std::endl;
    std::string str2 = getStr();
    std::cout << "The strings together are" << std::endl;
    std::cout << str1 << " " << str2 << std::endl;
}

int main(){
    concatStr();
    return 0;
}