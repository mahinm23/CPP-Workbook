#include <iostream>
#include <vector>

void fillArr(std::vector<int>& a) {
    for (int i=0; i<a.size(); i++) {
        a[i] = rand() % 10 + 1;
    }
}

void printArr(std::vector<int> a) {
    int itemsPerLine = 4;
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
        if ((i + 1) % itemsPerLine == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void subset(std::vector<int> a, std::vector<int> b) {
    for (int i=0; i<a.size(); i++) {
        
    }
}

int main() {
    srand(time(0));
    std::vector<int> arr_a(20);
    std::vector<int> arr_b(20);

    fillArr(arr_a);
    fillArr(arr_b);

    printArr(arr_a);
    printArr(arr_b);

    return 0;
}