#include <iostream>

void change_calc(int difference) {
    int coin100;
    int coin50;
    int coin20;
    int coin10;
    int coin5;
    int coin2;
    int coin1;

    coin100 = difference / 100;
    difference = difference - coin100*100;

    coin50 = difference / 50;
    difference = difference - coin50*50;

    coin20 = difference / 20;
    difference = difference - coin20*20;

    coin10 = difference / 10;
    difference = difference - coin10*10;
    
    coin5 = difference / 5;
    difference = difference - coin5*5;

    coin2 = difference / 2;
    difference = difference - coin2*2;

    coin1 = difference / 1;
    difference = difference - coin1*1;

    std::cout << "Change Required: " << std::endl;
    std::cout << coin100 << " £1 coins required" << std::endl;
    std::cout << coin50 << " 50p coins required" << std::endl;
    std::cout << coin20 << " 20p coins required" << std::endl;
    std::cout << coin10 << " 10p coins required" << std::endl;
    std::cout << coin5 << " 5p coins required" << std::endl;
    std::cout << coin2 << " 2p coins required" << std::endl;
    std::cout << coin1 << " 1p coins required" << std::endl;
}

int diff_calc(float amount, float given) {
    int diff = (given-amount)*100;
    return diff;
}

int main() {
    float amount;
    std::cout << "What was the cost of the item?" << std::endl;
    std::cin >> amount;

    float given;
    std::cout << "What was the amount of cash given" << std::endl;
    std::cin >> given;

    int difference = diff_calc(amount, given);
    change_calc(difference);
    return 0;
}