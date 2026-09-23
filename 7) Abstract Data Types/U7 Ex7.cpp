#include <iostream>
#include <string>

const int MAX = 50;

struct Olympians {
    std::string names[MAX];
    std::string medals[MAX];
    int count;
};

Olympians createEmptyDatabase() {
    // YOUR CODE
    Olympians db;
    db.count = 0;
    return db;
}

void addRecord(Olympians& db, std::string name, std::string medal) {
    // YOUR CODE
    if (db.count >= MAX){
        std::cout << "DB full" << std::endl;
    }
    db.names[db.count] = name;
    db.medals[db.count] = medal;
    db.count ++;
}

int findRank(std::string med){
    if (med == "Gold"){
        return 3;
    } else if (med == "Silver"){
        return 2;
    } else if (med == "Bronze"){
        return 1;
    } else {
        return 0;
    }
}

std::string highestMedalOf(Olympians& db, std::string name) {
    // YOUR CODE — linear search by name, return their medal (or "unknown")
    std::string highest = "unknown";
    int cur_rank;
    int highest_rank = 0;
    for (int i=0; i<db.count; i++){
        if (db.names[i] == name){
            cur_rank = findRank(db.medals[i]);
            if (cur_rank > highest_rank){
                highest = db.medals[i];
                highest_rank = cur_rank;
            }
        }
    }
    return highest;
}


int main() {
    Olympians db = createEmptyDatabase();
    addRecord(db, "Sarah Storey", "Gold");
    addRecord(db, "Sarah Storey", "Silver");
    addRecord(db, "Kadeena Cox", "Silver");
    std::cout << highestMedalOf(db, "Sarah Storey") << std::endl;
    std::cout << highestMedalOf(db, "Mahin") << std::endl;
    return 0;
}
