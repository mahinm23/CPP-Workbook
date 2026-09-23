#include <iostream>
#include <string>

const int MAX_ENTRIES = 20;

void inputDetails(std::string names[], std::string numbers[], int& count) {
    // YOUR CODE
    std::string name;
    std::string num;
    std::string choice;
    
    std::cout << "How many numbers do you want to input " << std::endl;
    std::getline(std::cin, choice);
    count = std::stoi(choice);

    for (int i = 0; i < count; i++){
        std::cout << "Enter a name " << std::endl;
        std::getline(std::cin, name);
        names[i] = name;
        std::cout << "Enter a number " << std::endl;
        std::getline(std::cin, num);
        numbers[i] = num;
    }
}

void search(std::string names[], std::string numbers[], int count, std::string target) {
    // YOUR CODE — linear search
    for (int i = 0; i < count; i++){
        if (names[i] == target){
            std::cout << numbers[i] << std::endl;
            return;
        }
    }
    std::cout << "Not Found" << std::endl;
}

int main() {
    std::string names[MAX_ENTRIES];
    std::string numbers[MAX_ENTRIES];
    int count = 0;
    inputDetails(names, numbers, count);
    std::string query;
    while (true) {
        std::cout << "Enter name to search (or quit): ";
        std::getline(std::cin, query);
        if (query == "quit") break;
        search(names, numbers, count, query);
    }
    return 0;
}