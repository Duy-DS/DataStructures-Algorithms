#include <iostream>
using namespace std;

// Function to implement the bidirectional sort algorithm based on bubble sort
void bidirectional_sort(int arr[], int n) {
    // Initialize two pointers, left and right
    int left = 0;
    int right = n - 1;

    // Continue the loop until left is greater than or equal to right
    while (left < right) {
        // Sort the sublist from left to right in ascending order using bubble sort
        for (int i = left; i < right; i++) {
            // Swap adjacent elements if they are in the wrong order
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }

        // Decrement the right pointer
        right--;

        // Sort the sublist from right to left in descending order using bubble sort
        for (int i = right; i > left; i--) {
            // Swap adjacent elements if they are in the wrong order
            if (arr[i - 1] > arr[i]) {
                swap(arr[i], arr[i - 1]);
            }
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
