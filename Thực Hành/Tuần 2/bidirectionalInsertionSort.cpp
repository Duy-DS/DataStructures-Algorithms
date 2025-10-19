#include <iostream>
using namespace std;

// Function to implement the bidirectional sort algorithm based on insertion sort
void bidirectional_sort(int arr[], int n) {
    // Initialize two pointers, left and right
    int left = 0;
    int right = n - 1;

    // Continue the loop until left is greater than or equal to right
    while (left < right) {
        // Sort the sublist from left to right in ascending order using insertion sort
        for (int i = left + 1; i <= right; i++) {
            // Store the current element in a key variable
            int key = arr[i];
            int j = i - 1;

            // Shift all elements that are greater than the key to the right
            while (j >= left && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            // Insert the key into its correct position
            arr[j + 1] = key;
        }

        // Decrement the right pointer
        right--;

        // Sort the sublist from right to left in descending order using insertion sort
        for (int i = right; i >= left; i--) {
            // Store the current element in a key variable
            int key = arr[i];
            int j = i + 1;

            // Shift all elements that are less than the key to the left
            while (j <= right && arr[j] < key) {
                arr[j - 1] = arr[j];
                j++;
            }

            // Insert the key into its correct position
            arr[j - 1] = key;
        }

        // Increment the left pointer
        left++;
    }
}

int main() {
    int arr[] = {0, 64, 11, 12, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Call the bidirectional sort function
    bidirectional_sort(arr, n);

    // Output the sorted array
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
