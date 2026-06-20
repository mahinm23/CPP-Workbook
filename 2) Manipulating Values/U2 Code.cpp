#include <iostream>

std::string getInfo(){
    std::string str;
    std::getline(std::cin, str);
    return str;
}

struct Person {
    std::string name;
    std::string dob;
};

std::string getName(Person p) {
    return p.name;
}

Person setName(Person p, std::string newName) {
    p.name = newName;
    return p;
}

int main() {

    int myint = 23;
    char mychar = 'm';
    std::cout << myint << " " << mychar <<std::endl;

    std::cout << "Whats your int ";
    std::string myi = getInfo();
    int i = std::stoi(myi);
    std::cout << "I parsed " << i << " as an int" << std::endl;
    std::cout << i << "^2 is " << (i*i) << std::endl;

    srand(time(0));
    int dice = rand() % 6 + 1;
    std::cout << "Your dice throw got " << dice << std::endl;

    Person dude;
    dude = setName(dude, "Lad");
    dude.dob = "231104";
    std::cout << getName(dude) << dude.dob << std::endl; 

    return 0;
}