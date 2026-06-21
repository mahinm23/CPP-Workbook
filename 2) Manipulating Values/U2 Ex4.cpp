#include <iostream>

struct Rectangle {
    int length;
    int width;
};

int getLen(Rectangle r) {return r.length;}
int getWid(Rectangle r) {return r.width;}

int getInt(std::string message) {
    std::cout << message << std::endl;
    int num;
    std::cin >> num;
    return num;
}

int main() {
    Rectangle r;
    r.length = getInt("Enter rectangle length");
    r.width = getInt("Enter rectangle width");

    std::cout << getLen(r) * getWid(r) << " is the area of your rectangle" << std::endl;

    return 0;
}