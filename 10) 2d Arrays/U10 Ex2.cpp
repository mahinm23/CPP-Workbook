#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void printArray(int arr[], int length) {
    std::cout << " " << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
        if ((i+1) % 4 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void bubbleSortDesc(int arr[], int length) {
    // Change: swap when arr[i] < arr[i+1] for descending
    // YOUR CODE
    int temp;
    int comparisons;
    for (int pass = 1; pass <= length; pass++)
    {
        for (int i = 0; i < length - pass; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                swap(arr, i, i + 1);
                comparisons += 1;
            }
        }
    }
    std::cout << "Comparisons " << comparisons << std::endl;
}

int main() {
    srand(time(0));
    int arr[20];
    for (int i = 0; i < 20; i++) arr[i] = rand() % 100;

    std::cout << "Before: "; printArray(arr, 20);
    bubbleSortDesc(arr, 20);
    std::cout << "After: "; printArray(arr, 20);
    return 0;
}
