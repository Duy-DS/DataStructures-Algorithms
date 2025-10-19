#include <iostream>
using namespace std;

// hàm in ra các giá trị trong mảng
void printArray(int* arr, int arrSize) {
    for(int i = 0; i < arrSize; i++)
        cout<<arr[i]<< " ";
    cout << endl;
}

// hàm đổi chỗ 2 số nguyên
void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}

// hàm sắp xếp chèn
void selectionSort(int arr[], int n){
    int i, j, min_idx;
    // Sắp xếp từng giá trị từ
    for (i = 0; i < n-1; i++){
        // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])  // comparison
                min_idx = j;
        // Đổi chỗ phần tử nhỏ nhất với phần tử thứ i
        swap(arr[min_idx], arr[i]); // swap
    }
}

int main() {
    int size = 14;
    int arr[14] = {2, 2, 1, 2, 0, 0, 1, 1, 1, 0, 0, 1, 2, 1};
    selectionSort(arr, size);
    printArray(arr, size);
}