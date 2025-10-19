
#include <iostream>
#include <cstdlib>

using namespace std;

// hàm khởi tạo giá trị ngẫu nhiên cho mảng
void fillArray(int list[], int length)
{
    srand(time(0));

    for (int i = 0; i < length; i++)
        list[i] = rand() % 20000;
}

// hàm sao chép mảng
void copyArray(int list1[], int list2[], int length)
{
    for (int i = 0; i < length; i++)
        list2[i] = list1[i];
}

// hàm để đổi vị trí hai phần tử
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// hàm để để phân chia mảng dựa theo giá trị pivot
int partition(int array[], int low, int high, int& comp, int& assign) {

    // chọn phần tử ngoài cùng bên phải làm giá trị pivot
    int pivot = array[high];
    // đếm số lần gán giá trị cho biến pivot
    assign++;
    // tạo con trỏ cho phần tử lớn hơn khi so sánh
    int i = (low - 1);

    // duyệt qua từng phần tử của mảng và so sánh với giá trị pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            // nếu phần tử đang được duyệt nhỏ hơn phần tử pivot
            // thực hiện việc đổi chỗ với phần tử thứ i
            i++;
            swap(&array[i], &array[j]);
            // đếm số lần gán
            assign = assign + 3;
        }
        // đếm số lần so sánh (trong hàm if)
        comp++;
    }

    // đổi chỗ phần tử pivot với phần tử tại i
    swap(&array[i + 1], &array[high]);
    // đếm số lần gán
    assign = assign + 3;
    // trả về index của giá trị pivot
    return (i + 1);
}

void quickSort(int array[], int low, int high, int& comp, int& assign) {
    if (low < high) {
        // tìm index của giá trị pivot để thực hiện việc phân chia
        // mảng bên trái bao gồm các phần tử nhỏ hơn giá trị pivot
        // mảng bên phải bao gồm các phần tử lớn hơn giá trị pivot
        int pi = partition(array, low, high, comp, assign);

        // thực hiện việc sắp xếp đệ quy cho mảng con ở bên trái
        // và bên phải pivot
        quickSort(array, low, pi - 1,comp, assign);
        quickSort(array, pi + 1, high,comp, assign);
    }
}

void insertionSort(int array[], int size, int& comp, int& assign) {
    for (int i = 1,j; i < size; i++) {
        int tmp = array[i]; // lưu lại giá trị thứ 2

        for (j = i; j > 0 && tmp < array[j-1]; j--){
            array[j] = array[j-1];
            comp++; // đếm một lần so sánh: tmp < array[j-1]
            assign++; // đếm một lần gán: array[j] = array[j-1]
        }

        // thực hiện việc chèn giá trị
        array[j] = tmp;
        assign = assign + 2; // đếm 2 lần gán: tmp = array[i] và array[j] = tmp
    }
}

void merge(int array[], int left, int mid, int right, int& comp) {
    int i, j, k;

    // tìm index bắt đầu và index kết thúc của mảng con
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    // khởi tạo hai mảng con tạm thời
    int leftArr[sizeLeft], rightArr[sizeRight];

    // sao chép dữ liệu từ mảng gốc vào hai mảng con
    for (i = 0; i < sizeLeft; i++){
        // lưu ý: khái niệm so sánh ở đây là so sánh giá trị phần tử
        // nên i < sizeLeft không được tính vào số lần so sánh trong merge sort
        leftArr[i] = array[left + i];
    }
    for (j = 0; j < sizeRight; j++){
        // lưu ý: khái niệm so sánh ở đây là so sánh giá trị phần tử
        // nên j < sizeRigh không được tính vào số lần so sánh trong merge sort
        rightArr[j] = array[mid + 1 + j];
    }

    // Lần lượt gộp các mảng con lại
    i = 0; // Khởi tạo index cho mảng con đầu tiên
    j = 0; // Khởi tạo index cho mảng con thứ hai
    k = left; // Khởi tạo index cho mảng kết quả gộp

    // lặp qua từng mảng con và sao chép giá trị nhỏ nhất vào mảng kết quả gộp
    while (i < sizeLeft && j < sizeRight) {
        // lưu ý: khái niệm so sánh ở đây là so sánh giá trị phần tử
        // nên i < sizeLeft và j < sizeRight không được tính vào số lần so sánh trong merge sort
        if (leftArr[i] <= rightArr[j]) {
            array[k] = leftArr[i];
            i++;
            comp++;
        } else {
            array[k] = rightArr[j];
            j++;
            comp++;
            // lưu ý: việc so sánh chỉ được thực hiện 1 lần
            // nhưng cần phải tăng giá trị của biến đếm comp ở cả hai trường hợp if và else
            // nếu không sẽ bị mấy số lượng so sánh ở toàn bộ 1 trường hợp if hoặc else.
        }
        k++;
    }

    // sap chép phần tử còn lại của mảng leftArr[] vào mảng kết quả
    while (i < sizeLeft) {
        array[k] = leftArr[i];
        i++;
        k++;
    }

    // sap chép phần tử còn lại của mảng rightArr[] vào mảng kết quả
    while (j < sizeRight) {
        array[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int leftIndex, int rightIndex, int& comp) {
    // kiểm tra tính hợp lệ
    if(leftIndex < 0 || rightIndex < 0){
        return;
    }

    if(rightIndex > leftIndex) {
        // lưu ý: khái niệm so sánh ở đây là so sánh giá trị phần tử
        // nên rightIndex > leftIndex không được tính vào số lần so sánh trong merge sort

        // xác định index của phần tử ở giữa của mảng con
        int mid = leftIndex + (rightIndex - leftIndex) / 2;

        // sắp xếp đệ quy hai mảng con bên trái và bên phải
        mergeSort(array, leftIndex, mid, comp);
        mergeSort(array, mid + 1, rightIndex, comp);

        // gộp các mảng con
        merge(array, leftIndex, mid, rightIndex, comp);
    }
}

int main()
{
    // khởi tạo biến
    int n = 5000; // thay đổi số lượng phần tử của mảng
    int array1[n];
    int array2[n];
    int array3[n];

    // tạo biến đếm
    int compQuickSort = 0, compMergeSort = 0, compInsertionSort = 0;
    int assignQuickSort = 0, assignInsertionSort = 0;

    // tạo giá trị ngẫn nhiên cho mảng đầu tiên
    fillArray(array1, n);

    // sao chép giá trị của mảng đầu tiên vào mảng thứ hai và thứ ba
    copyArray(array1, array2, n);
    copyArray(array1, array3, n);

    // thực hiện quick sort cho mảng array1
    quickSort(array1, 0, n - 1, compQuickSort, assignQuickSort);

    // thực hiện insertion sort cho mảng array2
    insertionSort(array2, n, compInsertionSort, assignInsertionSort);

    // thực hiện merge sort cho mảng array3
    mergeSort(array3, 0, n - 1, compMergeSort);


    cout << "Số lần so sánh---" << endl;
    cout << "  Quick sort: " << compQuickSort << endl;
    cout << "  Merge sort: " << compMergeSort << endl;
    cout << "  Insertion sort: " << compInsertionSort << endl << endl;

    cout << "Số lần gán---" << endl;
    cout << "  Quick sort: " << assignQuickSort << endl;
    cout << "  Insertion sort: " << assignInsertionSort << endl << endl;

    return 0;
}

