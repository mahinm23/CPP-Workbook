#include <iostream>
#include <string>

int inp_int(std::string s){
    int num;
    std::string ans;

    while(true){
        std::cout << s << std::endl;

        std::getline(std::cin, ans);
        try {
            num = std::stoi(ans);
            return num;
        } catch (const std::exception& e){
            std::cout << "Please enter a number " << std::endl;
        } 
    }
}

int fibbo(int n){
    if (n == 0) return 1;
    if (n == 1) return 1;
    return fibbo(n-1) + fibbo(n-2);
}

int exp(int n, int m){
    if (m == 0) return 1;
    return n * exp(n, m - 1);
}

int gcd(int m, int n){
    if (m == 0) return 0;
    if (m == n) return m;
    if (n < m){
        return gcd(n, m);
    } else{
        return gcd(m, n-m);
    }
}

int main(){
    int choice;
    int var1;
    int var2;
    int ans;

    while(true){
        std::cout << " " << std::endl;
        std::cout << "Enter your choice " << std::endl;
        std::cout << "1 for fibbonacci " << std::endl;
        std::cout << "2 for exponent " << std::endl;
        std::cout << "3 for gcd " << std::endl;
        std::cout << "Anything else to quit " << std::endl;

        choice = inp_int(" ");

        if (choice == 1){
            var1 = inp_int("Enter a number to find fibbonacci up to");
            ans = fibbo(var1);
        } else if (choice == 2) {
            var1 = inp_int("Enter the base");
            var2 = inp_int("Enter the exponent");
            ans = exp(var1, var2);
        } else if (choice == 3) {
            var1 = inp_int("Enter the first term for gcd");
            var2 = inp_int("Enter the second term for gcd");
            ans = gcd(var1, var2);
        } else {
            std::cout << "Exiting " << std::endl;
            break;
        }
        
        std::cout << "The answer is " << ans << std::endl;
    }
    
    return 0;
}