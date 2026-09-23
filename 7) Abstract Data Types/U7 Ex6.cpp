#include <iostream>

const int MAX = 10;

struct Queue {
    std::string entries[MAX];
    int numberQueueing;
};

Queue createEmptyQueue() {
    Queue q;
    q.numberQueueing = 0;
    return q;
}

void joinQueue(Queue& q, std::string newEntry) {
    if (q.numberQueueing < MAX) {
        q.entries[q.numberQueueing] = newEntry;
        q.numberQueueing++;
    }
}

std::string leaveQueue(Queue& q) {
    std::string front = q.entries[0];
    if (q.numberQueueing != 0) {
        for (int i = 0; i < q.numberQueueing; i++) {
            q.entries[i] = q.entries[i + 1];
        }
        q.numberQueueing--;
    }
    return front;
}

std::string firstInQueue(Queue& q) {
    return q.entries[0];
}

int main() {
    Queue q = createEmptyQueue();
    joinQueue(q, "Alistair Brownlee");
    std::cout << firstInQueue(q) << std::endl;
    joinQueue(q, "Mo Farah");

    bool running = true;
    int choice;
    std::string name;
    std::string res;
    while (running){
        if (q.numberQueueing > 0){
        std::cout << firstInQueue(q) << " is first" << std::endl;
        } else {
            std::cout << "The queue is empty" << std::endl;
        }
        
        std::cout << "Enter 1 to join the queue" << std::endl;
        std::cout << "Enter 2 to leave the queue" << std::endl;
        std::cout << "Enter anything to quit" << std::endl;
        std::cin >> choice;
        if (choice == 1){
            std::cout << "Enter name" << std::endl;
            std::cin >> name;
            joinQueue(q, name);
        } else if (choice == 2){
            res = leaveQueue(q);
            std::cout << res << std::endl;
        } else {
            running = false;
        }
    }


    return 0;
}