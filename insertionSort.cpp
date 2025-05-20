#include <iostream>

void insertionSort(int arr[], int size) {
    int i, j, key;
    //forward iteration
    for (int i = 1; i < size; i++) {
        //key is the number we are trying to place
        int key = arr[i];
        //backward iterator (starts just ahead of i)
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            //If the number is greater than key, we move it one position ahead
            arr[j + 1] = arr[j];
            j--;
        }
        //Place the key in its correct position
        arr[j + 1] = key;
    }
}
 
void print(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    print(arr, size);
    return 0;
}