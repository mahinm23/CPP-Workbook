#include <iostream>
#include <vector>

int search(int a[], int n, int size) {
    for (int i=0; i<size; i++) {
        if (a[i] == n) {
            std::cout << "Found element in index " << i << std::endl;
            return i;
        }
    }
    std::cout << "Element not found, returning -1" << std::endl;
    return -1;
}

int main() {
    int values[10];
    const int SIZE = 10;
    for (int i=0; i<SIZE; i++) {
        values[i]=i;
    }

    for (int i=0; i<SIZE; i++) {
        std::cout << values[i] << std::endl;
    }
    std::cout << " " << std::endl;

    std::vector<std::string> ppl;
    ppl.push_back("Bear");
    std::cout << ppl.size() << std::endl;
    std::cout << ppl[0] << std::endl;
    ppl.push_back("Dude");
    ppl.erase(ppl.begin() + 0);
    std::cout << ppl.size() << std::endl;
    std::cout << ppl[0] << std::endl;
    std::cout << " " << std::endl;
    ppl.push_back("Hello");
    ppl.push_back("World");
    for (int i=0; i<ppl.size(); i++) {
        std::cout << ppl[i] << std::endl;
    }
    std::cout << " " << std::endl;

    int nums[6] = {1, 3, 4, 7, 9, 10};
    int idx = search(nums, 3, 6);
    std::cout << idx << std::endl;


    return 0;
}