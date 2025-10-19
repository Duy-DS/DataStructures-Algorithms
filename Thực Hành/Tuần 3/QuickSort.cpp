#include <iostream>
using namespace std;
using namespace std::chrono;

// hàm đổi vị trí hai phần tử
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// hàm in mảng
void printArray(int array[], int size) {
    for ( int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// hàm tìm điểm để chia mảng thành hai mảng con
int partition(int array[], int low, int high, int pivot_idx) {
    // Đổi chỗ vị trí của giá trị pivot về cuối mảng
    swap(array[high],array[pivot_idx]);

    // tạo giá trị pivot dựa trên index được truyền vào
    int pivot = array[high];

    // con trỏ chỉ về phần tử có giá trị lớn hơn
    int i = (low - 1);

    // duyệt mảng và so sánh các phần tử với giá trị pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

            // nếu phần tử nhỏ hơn giá trị pivot,
            // thực hiện việc đổi chỗ với giá trị lớn hơn
            i++;
            swap(&array[i], &array[j]);
        }
    }

    // đổi chõ giá trị pivot với phần tử lớn hơn tại i
    swap(&array[i + 1], &array[high]);

    // trả về index của phần tử pivot
    return (i + 1);
}

void quickSort_default(int array[], int low, int high) {
    if (low < high) {
        // tìm index của giá trị pivot
        // để chia mảng thành hai mảng con
        int pi = partition(array, low, high, high);

        // đệ quy với các phần tử bên trái nhỏ hơn pivot
        quickSort_default(array, low, pi - 1);

        // đệ quy với các phần tử bên phải lớn hơn pivot
        quickSort_default(array, pi + 1, high);
    }
}

void quickSort_randomPivot(int array[], int low, int high) {
    if (low < high) {
        // TODO 1: chọn index ngẫu nhiên rand_pivot_idx trong mảng
        // để thay thế tham số high của hàm partition
        
        // tìm index của giá trị pivot
        // để chia mảng thành hai mảng con
        int pi = partition(array, low, high, rand_pivot_idx);

        // đệ quy với các phần tử bên trái nhỏ hơn pivot
        quickSort_default(array, low, pi - 1);

        // đệ quy với các phần tử bên phải lớn hơn pivot
        quickSort_default(array, pi + 1, high);
    }
}

void quickSort_Median(int array[], int low, int high) {
    if (low < high) {
        // TODO 2: chọn giá trị trung vị median_idx của phần tử đầu tiên
        // phần tử ở giữa mảng và phần tử cuối cùng
        // để thay thế tham số array[high] của hàm partition

        // tìm index của giá trị pivot
        // để chia mảng thành hai mảng con
        int pi = partition(array, low, high, median_idx);

        // đệ quy với các phần tử bên trái nhỏ hơn pivot
        quickSort_default(array, low, pi - 1);

        // đệ quy với các phần tử bên phải lớn hơn pivot
        quickSort_default(array, pi + 1, high);
    }
}

int main() {
    // tạo mảng với giá trị ngẫu nhiên
    int n = 1000;
    int data[n];
    srand((unsigned)time(0));
    for(int i=0; i<n; i++){
        data[i] = (rand()%100)+1;
    }

//    cout << "Mảng chưa được sắp xếp: \n";
//    printArray(data, n);

    // auto: xác định một biên có thời gian tự động
    auto start = high_resolution_clock::now();

    // thực hiện sắp xếp mặc định
    quickSort_default(data, 0, n - 1);

    auto stop = high_resolution_clock::now();

    // Tìm thời gian khác nhau
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Thời gian thực thi của thuật toán: "
         << duration.count() << " microseconds" << endl;

//    cout << "Mảng đã được sắp xếpr: \n";
//    printArray(data, n);
    // TODO 2: so sánh thời gian thực thi của các thuật toán với kích thước dữ liệu đầu vào khác nhau
}