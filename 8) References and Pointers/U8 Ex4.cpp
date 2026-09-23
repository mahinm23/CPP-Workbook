#include <iostream>

void doubleAll(int* arr, int size){
    for (int i = 0; i < size; i++){
        arr[i] = arr[i]*2;
    }
}

void printArr(int* arr, int size){
    for (int i=0; i<size; i++){
        std::cout << arr[i] << std::endl;
    }
    std::cout << " " << std::endl;
}

int main(){
    int arr[] = {1, 2, 3};
    printArr(arr, 3);
    doubleAll(arr, 3);
    printArr(arr, 3);
    return 0;
}