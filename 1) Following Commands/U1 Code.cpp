#include <iostream>

std::string askName() {
    std::string name;
    std::getline(std::cin, name);
    return name;
}

int main() {
    std::string name1;
    name1 = "jeff";
    std::string msg = "Hey, my names ";

    std::cout << name1 << std::endl;
    std::cout << msg + name1 << "!" << std::endl;
    std::cout << "" << std::endl;

    std::string name2;
    std::cout << "Whats your name?" << std::endl;
    std::getline(std::cin, name2);
    std::cout << "Hey, " << name2 << ", hows it going"<< std::endl;

    // std::int num1;
    // std::cout << "Pick a number" << std::endl;
    // std::cin >> num1;
    // std::cout << num1 << " is your number" << std::endl;

    std::cout << "Sorry i forgot it, what was your name again?";
    std::string name3 = askName();
    std::cout << "My bad, "<< name3 << ", ill remember this time" << std::endl;


    return 0;
}