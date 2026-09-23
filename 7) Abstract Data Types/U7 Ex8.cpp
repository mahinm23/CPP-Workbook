#include <iostream>
#include <string>

const int MAX = 50;

struct EAnims {
    std::string names[MAX];
    std::string status[MAX];
    int count;
};

EAnims createEmptyDB() {
    EAnims db;
    db.count = 0;
    return db;
}

void addAnimal(EAnims& db, std::string name, std::string status){
    if (db.count >= MAX){
        std::cout << "DB Full" << std::endl;
        return;
    }
    db.names[db.count] = name;
    db.status[db.count] = status;
    db.count ++;
}

std::string statusLookup(EAnims& db, std::string animal){
    for (int i=0; i < db.count; i++){
        if (db.names[i] == animal){
            return db.status[i];
        }
    }
    return "Unknown";
}

int main(){
    EAnims db = createEmptyDB();
    addAnimal(db, "Dodo", "Extinct");
    addAnimal(db, "Dog", "notInDanger");
    addAnimal(db, "Tiger", "Endangered");
    addAnimal(db, "Car", "notInDanger");
    std::string check = statusLookup(db, "Tiger");
    std::cout << "Tiger: " << check << std::endl;
}