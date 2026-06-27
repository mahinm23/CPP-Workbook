#include <iostream>

struct Planet {
    std::string name;
    int dist_sun;
    int position;
};

std::string getPlanet(Planet p) {return p.name;}

int getPos(Planet p) {return p.position;}

int getDist(Planet p) {return p.dist_sun;}


Planet setPos(Planet p, int pos) {
    p.position = pos;
    return p;
}

Planet setDist(Planet p, int dist) {
    p.dist_sun = dist;
    return p;
}

Planet setName(Planet p, std::string n) {
    p.name = n;
    return p;
}

int main() {
    Planet mercury;
    mercury = setName(mercury, "Mercury");
    mercury = setPos(mercury, 1);

    Planet venus;
    venus = setName(venus, "Venus");
    venus = setPos(venus, 2);

    Planet earth;
    earth = setName(earth, "Earth");
    earth = setPos(earth, 3);

    Planet mars;
    mars = setName(mars, "Mars");
    mars = setPos(mars, 4);
    
    std::cout << "Enter a planet name from mercury to mars" << std::endl;
    std::string p;
    std::getline(std::cin, p);

    if (p == getPlanet(mercury)) {
        std::cout << "The position of " << getPlanet(mercury) << " is " << getPos(mercury) << std::endl;
    } else if (p == getPlanet(venus)) {
        std::cout << "The position of " << getPlanet(venus) << " is " << getPos(venus) << std::endl;
    } else if (p == getPlanet(earth)) {
        std::cout << "The position of " << getPlanet(earth) << " is " << getPos(earth) << std::endl;
    } else if (p == getPlanet(mars)) {
        std::cout << "The position of " << getPlanet(mars) << " is " << getPos(mars) << std::endl;
    } else {
        std::cout << "Invalid planet name" << std::endl;
    }
    
}