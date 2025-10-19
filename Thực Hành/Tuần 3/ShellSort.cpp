#include <iostream>
using namespace std;
using namespace std::chrono;

void Shellsort(int array[], int n) {
    int i, j, hCnt, h;
    int increments[20], k;

    // TODO 1: thay đổi các giá trị của mảng tăng dần
    // tạo mảng tăng dần h
    for (h = 1, i = 0; h < n; i++) {
        increments[i] = h;
        h = 3 * h + 1;
    }
    // sắp xết các phần tử cách nhau h đơn vị
    for (i--; i >= 0; i--) {
        h = increments[i];
        // loop on the number of subarrays h-sorted in ith pass
        // duyệt và sắp xếp các phẩn tử của các mảng con
        for (hCnt = h; hCnt < 2 * h; hCnt++) {
            // sắp xếp chèn với mỗi mảng con
            for (j = hCnt; j < n;) { // array data
                int tmp = array[j];
                k = j;
                while (k - h >= 0 && tmp < array[k - h]) {
                    array[k] = array[k - h];
                    k -= h;
                }
                array[k] = tmp;
                j += h;
            }
        }
    }
}

// hàm in mảng
void printArray(int array[], int size) {
    for ( int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
int main() {
    // tạo mảng với giá trị ngẫu nhiên
    int n = 100;
    int data[n];
    srand((unsigned)time(0));
    for(int i=0; i<n; i++){
        data[i] = (rand()%100)+1;
    }

    // auto: xác định một biên có thời gian tự động
    auto start = high_resolution_clock::now();

    // thực hiện sắp xếp mặc định
    Shellsort(data, n);

    auto stop = high_resolution_clock::now();

    // Tìm thời gian khác nhau
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Thời gian thực thi của thuật toán: "
         << duration.count() << " microseconds" << endl;

    printf("Sorted Array Using Shell Sort: \n");
    printArray(data, n);
    // TODO 2: so sánh thời gian thực thi của các thuật toán với kích thước dữ liệu đầu vào khác nhau
}