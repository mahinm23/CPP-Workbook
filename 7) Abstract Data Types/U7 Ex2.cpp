#include <iostream>

int plusOne(int a){
    return a+1;
}

int main(){
    int val;
    std::cout << "Enter a number" << std::endl;
    std::cin >> val;
    std::cout << val << " + 1 is " << plusOne(val) << std::endl;

    return 0;
}