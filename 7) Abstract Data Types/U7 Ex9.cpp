#include <iostream>
#include <string>

const int MAX = 50;

struct Stack{
    int numbers[MAX];
    int count;
};

Stack createEmptyDB(){
    Stack db;
    db.count = 0;
    return db;
}

int top(Stack& arr){
    if (arr.count == 0){
        std::cout << "Stack is empty" << std::endl;
        return -1;
    } else {
        return arr.numbers[arr.count-1];
    }
}

void push(Stack& arr, int num){
    if (arr.count >= MAX){
        std::cout << "Stack full" << std::endl;
    } else{
        arr.numbers[arr.count] = num;
        arr.count ++;
    }
}

int pop(Stack& arr){
    if (arr.count == -0){
        std::cout << "Stack empty";
        return -1;
    } else{
        int ret_val = arr.numbers[arr.count-1];
        arr.count --;
        return ret_val;
    }
} 

int main(){
    Stack s = createEmptyDB();

    push(s, 1);
    push(s, 2);
    push(s, 3);

    std::cout << "top: " << top(s) << std::endl;

    std::cout << pop(s) << std::endl;
    std::cout << pop(s) << std::endl;
    std::cout << pop(s) << std::endl;
    std::cout << pop(s) << std::endl;

    return 0;
}