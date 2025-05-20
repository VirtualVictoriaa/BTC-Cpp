// InsertionSort.cpp
// https://www.youtube.com/watch?v=8oJS1BMKE64

#include <iostream>

// Quick Sort
// This function takes the last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); // index of smaller element
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] >= pivot) {
            i++; // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(arr, low, pi - 1); //Left of pivot(partition index)
        quickSort(arr, pi + 1, high);//Right of pivot
    }
}

// Insertion Sort
void insertionSort(int arr[], int size)
{
    int i, j, key;
    // iterate through the array, starting at position 1
    for (i = 1; i < size; i++)
    {
        // key is the current item, we need to determine if it should move
        key = arr[i];
        // j is the previous index and will allow us to shift items forward
        j = i - 1;
        // Shift everything from arr[0..i-1] that is greater than the key
        // No if's req'd as this guarantees everything ahead is already sorted
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << '\n';
}

int main()
{
    int numbers[] = { 9, 0, 5, 3, 8, 1, 4, 6, 7, 10, 2 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    quickSort(numbers, 0, size - 1);
    print(numbers, size);

    return 0;
}