#include <iostream>

void fillArr(std::vector<int>& a) {
    for (int i=0; i<a.size(); i++) {
        a[i] = rand() % 100 + 1;
    }
}

int findMax(std::vector<int> a) {
    int max = 0;

    for (int i=1; i<a.size(); i++) {
        if (a[i] > a[max]) {
            max = i;
        }
    }
    return max;
}

int main() {
    srand(time(0));
    std::vector<int> arr(30);
    int idx;

    fillArr(arr);
    idx = findMax(arr);
    std::cout << "The highest number was " << arr[idx] << std::endl;
    std::cout << "The index was " << idx << std::endl;

    for (int x: arr) {
        std::cout << x << " ";
    }

    return 0;
}