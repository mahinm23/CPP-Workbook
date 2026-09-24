#include <iostream>

int sumToN(int n){
    if (n == 0) return 0;
    else if (n == 1) return 1;
    return n + sumToN(n-1);
}

int main(){
    int sum = sumToN(5);
    std::cout << sum << std::endl;
    return 0;
}