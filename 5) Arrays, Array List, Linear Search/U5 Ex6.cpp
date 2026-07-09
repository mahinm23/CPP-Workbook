#include <iostream>
#include <vector>

std::vector<int> arr_inp(int SIZE) {
    std::vector<int> res(SIZE);

    for (int i=0; i<SIZE; i++) {
        std::cout << "Enter number " << i << " :" << std::endl;
        std::cin >> res[i];
    }

    return res;
}

void print_threshold(std::vector<int> a, int n){
    for (int i=0; i<a.size(); i++) {
        if (a[i] > n){
            std::cout << a[i] << std::endl;
        }
    }
}

int main() {
    int threshold;
    std::cout << "Enter a threshold to print values over " << std::endl;
    std::cin >> threshold;

    int size;
    std::cout << "How big will your array be" << std::endl;
    std::cin >> size;
    std::cout << "" <<std::endl;

    std::vector<int> arr = arr_inp(size);
    print_threshold(arr, threshold);


    return 0;
}