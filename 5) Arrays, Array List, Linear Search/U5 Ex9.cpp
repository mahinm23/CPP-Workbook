#include <iostream>
#include <vector>

int linear_search(int n, std::vector<int> a) {
    int idx = -1;
    for (int i=0; i<a.size(); i++) {
        if (a[i] == n) {
            std::cout << "Found " << n << " at " << i << std::endl;
            return idx;
        }
    }
    std::cout << "Not found, returned -1" << std::endl;
    return idx;
}

std::vector<int> fillarr(int size, int bound) {
    std::vector<int> a(size);
    for (int i=0; i<size; i++) {
        a[i] = rand() % bound + 1;
    }
    return a;
}

int main() {
    int size;
    int bound;
    int num;
    std::vector<int> arr;
    int index;

    std::cout << "How big do you want your array to be" << std::endl;
    std::cin >> size;
    std::cout << "What number do you want the random numbers to generate until" << std::endl;
    std::cin >> bound;

    arr = fillarr(size, bound);

    std::cout << "Enter a number you want to search for" << std::endl;
    std::cin >> num;
    
    index = linear_search(num, arr); 
}