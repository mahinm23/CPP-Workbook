#include <iostream>

void hello(std::string name){
    std::cout << "Hello " << name << std::endl;
}

int main(){
    std::string n = "mahin";
    hello(n);
    hello(n);

    return 0;
}