////
//// Created by Sang Vu on 14/2/25.
////
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//// Function to print the array in a formatted way
//void print_array(int arr[], int size) {
//    int max_len = to_string(*max_element(arr, arr + size)).length();
//
//    // Print the index row
//    for (int i = 0; i < size; i++) {
//        cout << " " << setw(max_len + 2) << i;
//    }
//    cout << endl;
//
//    // Print the top border
//    cout << "+";
//    for (int i = 0; i < size; i++) {
//        cout << string(max_len + 4, '-') << "+";
//    }
//    cout << endl;
//
//    // Print the array elements
//    for (int i = 0; i < size; i++) {
//        cout << "| " << setw(max_len + 2) << arr[i] << " ";
//    }
//    cout << "|" << endl;
//
//    // Print the bottom border
//    cout << "+";
//    for (int i = 0; i < size; i++) {
//        cout << string(max_len + 4, '-') << "+";
//    }
//    cout << endl;
//}
//
//// Function to perform bubble sort
//void bubble_sort(int arr[], int size) {
//    for (int i = 0; i < size - 1; i++) {
//        cout << "\nLần lặp " << i + 1 << ":" << endl;
//        bool swapped = false;
//
//        for (int j = 0; j < size - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                swap(arr[j], arr[j + 1]);
//                swapped = true;
//            }
//        }
//
//        // Print array after each iteration
//        print_array(arr, size);
//
//        // If no elements were swapped, the array is already sorted
//        if (!swapped) break;
//    }
//}
//
//int main() {
//    int arr[] = {5, 16, 42, 31, 37, 66, 15, 2}; // predefined array
//    int size = sizeof(arr) / sizeof(arr[0]);
//
//    cout << "Mảng ban đầu:" << endl;
//    print_array(arr, size);
//    cout << endl;
//
//    bubble_sort(arr, size);
//
//    cout << "Mảng sau khi được sắp xếp:" << endl;
//    print_array(arr, size);
//
//    return 0;
//}
