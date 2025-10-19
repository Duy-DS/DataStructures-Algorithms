#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to choose pivot element
int choosePivot(int left, int right) {
    return left + (right - left) / 2;
}

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

// Function to partition the array
int partition(int arr[], int left, int right) {
    int pivotInd = choosePivot(left, right); // Index of pivot
    cout << "Pivot: " << arr[pivotInd] << endl;
    swap(arr[right], arr[pivotInd]); // Put the pivot at the end
    int pivot = arr[right]; // Pivot
    cout << "Swap the pivot with the right most element\n" ;
    printArray(arr, 9); // Print array after putting pivot

    int i = (left - 1); // All the elements less than or equal to the
    // pivot go before or at i

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++; // Increment the index
            cout << "Swap " << arr[i] << " and " << arr[j] << endl;
            swap(arr[i], arr[j]);
            cout << "Array after swapping: ";
            printArray(arr, right - left + 1); // Print array after swapping
        }
    }
    swap(arr[i + 1], arr[right]); // Put the pivot back in place
    cout << "Put pivot " << pivot << " in position " << (i + 1) << endl;
    cout << "Array after putting pivot: \n";
    printArray(arr, right - left + 1); // Print array after putting pivot
    cout << "\n";
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right); // pi is where the pivot is at
        printArray(arr, 9);
        // Separately sort elements before and after partition
        cout << "Partition at index " << pi << " with pivot " << arr[pi] << ":\n";
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}


int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: \n";
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
