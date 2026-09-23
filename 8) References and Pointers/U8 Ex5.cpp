#include <iostream>

void zeroOut(int arr[], int size, int& x){
    for (int i = 0; i<size; i++){
        arr[i] = 0;
    }
    x = 0;
}

void printArr(int* arr, int size){
    for (int i=0; i < size; i++){
        std::cout << arr[i] << std::endl;
    }
    std::cout << " " << std::endl;
}

int main(){
    int arr[] = {1, 2, 3};
    int y = 5;
    std::cout << y << std::endl;
    printArr(arr, 3);
    zeroOut(arr, 3, y);
    std::cout << y << std::endl;
    printArr(arr, 3);
    return 0;
}