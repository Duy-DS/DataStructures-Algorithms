#include <iostream>
using namespace std;

// Function to implement the bidirectional sort algorithm
void bidirectional_sort(int arr[], int n) {
    // Initialize two pointers, left and right
    int left = 0;
    int right = n - 1;

    // Continue the loop until left is greater than or equal to right
    while (left < right) {
        // Initialize variables to store the indices of the min and max elements
        int min_index = left;
        int max_index = right;

        // Find the minimum and maximum elements in the current sublist
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[min_index]) {
                min_index = i;
            }
            if (arr[i] > arr[max_index]) {
                max_index = i;
            }
        }

        // Swap the minimum element with the element at the left pointer
        swap(arr[left], arr[min_index]);

        // Check if the max element was swapped with the left pointer
        if (max_index == left) {
            max_index = min_index;
        }

        // Swap the maximum element with the element at the right pointer
        swap(arr[right], arr[max_index]);

        // Increment the left pointer and decrement the right pointer
        left++;
        right--;
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
