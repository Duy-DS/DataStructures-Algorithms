#include <iostream>
using namespace std;

// Function to print an array
void printArray(int arr[], int size) {
    cout << "Index: ";
    for (int i = 0; i < size; i++)
        cout << i << "\t\t";
    cout << endl;
    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << "[" << arr[i] << "]" << "\t\t";
    cout << endl;
}

// Function to perform Quick Sort
void quicksort(int data[], int first, int last) {
    int lower = first + 1, upper = last;
    swap(data[first], data[(first + last) / 2]);
    int bound = data[first];

    while (lower <= upper) {
        while (bound > data[lower])
            lower++;
        while (bound < data[upper])
            upper--;
        if (lower < upper)
            swap(data[lower++], data[upper--]);
        else
            lower++;
    }
    swap(data[upper], data[first]);

    if (first < upper - 1)
        quicksort(data, first, upper - 1);
    if (upper + 1 < last)
        quicksort(data, upper + 1, last);
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: \n";
    printArray(arr, n);
    quicksort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
