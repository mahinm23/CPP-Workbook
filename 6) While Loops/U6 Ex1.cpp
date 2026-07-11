#include <iostream>

int diceRoll() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(0));
    int roll;
     while (roll != 6) {
        roll = diceRoll();
        std::cout << roll << std::endl;
     }
     return 0;
}