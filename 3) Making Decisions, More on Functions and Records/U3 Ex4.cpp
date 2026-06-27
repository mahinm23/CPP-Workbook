#include <iostream>

int main() {
    int score;
    std::cout << "What was your score 0-100" << std::endl;
    std::cin >> score;
    if (score < 40) {
        std::cout << "Your grade is F";
    } else if ( score <= 44) {
        std::cout << "Your grade is E";
    } else if ( score <= 49) {
        std::cout << "Your grade is D";
    } else if ( score <= 59) {
        std::cout << "Your grade is C";
    } else if ( score <= 69) {
        std::cout << "Your grade is B";
    } else if ( score >= 70) {
        std::cout << "Your grade is C";
    } else {
        std::cout << "Invalid" << std::endl;
    }

    return 0;
}