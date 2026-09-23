#include <iostream>

int summer(int n){
    int ans = n*(n+1)/2;
    std::cout << "The sum of numbers 0 to " << n << " is " << ans <<std::endl;
    return ans;
}

int main(){
    int num;
    int ans;
    std::string choice = "1";

    while (choice == "1"){

        std::cout << "Please enter a number" << std::endl;
        std::cin >> num;
        ans = summer(num);

        std::cout << "1 to exit, anything else to continue" << std::endl;
        std::cin >> choice;
        if (choice == "1"){
            std::cout << "Exiting" << std::endl;
            choice = "0";
        }
    }
}