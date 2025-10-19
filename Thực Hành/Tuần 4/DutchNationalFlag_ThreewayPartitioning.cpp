#include <iostream>
using namespace std;

// hàm đổi chỗ 2 số nguyên trong mảng
void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void DutchNationalFlag(int array[], int size) {
    int i = 0; // index của các phẩn tử có giá trị là 0
    int mid = 0; // index của phần tử đang xét
    int j = size - 1; // index của các phần tử có giá trị là 2

    while (mid <= j) {
        // nếu phần tử đang xét bằng 0, thực hiện đổi chỗ với phần tử tại vị trí i
        if (array[mid] == 0) {
            // swap(array, i++, mid++); // tương đương với 3 dòng ở dưới
            swap(array, i, mid);
            i++;
            mid++;
        }
        // nếu phần tử đang xét bằng 2, thực hiện đổi chỗ với phần tử tại vị trí j
        else if (array[mid] == 2) {
            // swap(array, mid, j--); // tương đương với 2 dòng ở dưới
            swap(array, mid, j);
            j--;
        }
        // nếu phần tử đang xét bằng 1, tăng giá trị của biến đếm mid
        else if (array[mid] == 1) {
            mid++;
        }
    }
}

int main() {
    int size = 14;
    int data[14] = {2, 2, 1, 2, 0, 0, 1, 1, 1, 0, 0, 1, 2, 1};

    DutchNationalFlag(data, size);

    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    return 0;
}