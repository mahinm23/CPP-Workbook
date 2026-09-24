#include <iostream>
#include <string>

int binSearch(int target, int* arr, int left, int right){
    if (left > right) return -1;

    int middle = left + (right-left)/2;

    if (target == arr[middle]){
        return middle;
    } else if (target < arr[middle]){
        return binSearch(target, arr, left, middle-1);
    } else if (target > arr[middle]){
        return binSearch(target, arr, middle+1, right);
    } else return -1;
}

int main(){
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int goal;

    std::cout << "What number do you want to search for " << std::endl;
    std::cin >> goal;

    int res = binSearch(goal, list, 0, 9);
    std::cout << res << std::endl;

    return 0;
}