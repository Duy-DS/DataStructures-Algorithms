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
//// Function to print comments before the inner loop
//void print_comments_before(int i, int arr[], int size, int min_index) {
//    cout << "\nLần lặp " << i + 1 << ":" << endl;
//    cout << "   * Index của giá trị nhỏ nhất hiện tại: " << min_index << endl;
//    cout << "   * Giá trị nhỏ nhất hiện tại: " << arr[min_index] << endl;
//}
//
//// Function to print comments after the inner loop
//void print_comments_after(int i, int arr[], int size, int min_index) {
//    cout << "   * Giá trị nhỏ nhất thực tế: " << arr[min_index] << endl;
//    cout << "   * Đổi chỗ " << arr[i] << " và " << arr[min_index] << endl;
//    cout << endl;
//}
//
//// Function to perform selection sort
//void selection_sort(int arr[], int size) {
//    for (int i = 0; i < size - 1; i++) {
//        int min_index = i;
//        print_comments_before(i, arr, size, min_index);
//
//        for (int j = i + 1; j < size; j++) {
//            if (arr[j] < arr[min_index]) {
//                min_index = j;
//            }
//        }
//        print_comments_after(i, arr, size, min_index);
//
//        // Swap elements
//        swap(arr[i], arr[min_index]);
//
//        // Print array after each iteration
//        print_array(arr, size);
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
//    selection_sort(arr, size);
//
//    cout << "Mảng sau khi được sắp xếp:" << endl;
//    print_array(arr, size);
//
//    return 0;
//}
