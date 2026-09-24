#include <iostream>
#include <string>

int factorial(int n){
    if (n == 0) return 1;
    return n * factorial(n-1);
}

int main(){
    std::string input;
    int num;
    int ans;
    std::cout << "What number do you want the factorial for" << std::endl;
    std::getline(std::cin, input);
    num = std::stoi(input);

    ans = factorial(num);
    std::cout << ans << std::endl;
}