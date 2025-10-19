#include <iostream>
#include <ctime>

using namespace std;

const int SIZE = 10;  // Kích thước mảng
const int MAX_VAL = 100; // Giới hạn giá trị tối đa của phần tử trong mảng

// 1. Xác định số lượng phần tử duy nhất
int mostFrequentUniqueElements(int arr[], int n) {
    int uniqueVals[SIZE];
    int countVals[SIZE];
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == uniqueVals[j]) {
                countVals[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueVals[uniqueCount] = arr[i];
            countVals[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    int maxCount = 0, mostFrequent = uniqueVals[0];
    for (int i = 0; i < uniqueCount; i++) {
        if (countVals[i] > maxCount) {
            maxCount = countVals[i];
            mostFrequent = uniqueVals[i];
        }
    }

    return mostFrequent;
}

// 2. Sắp xếp bằng Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Tìm giá trị xuất hiện nhiều nhất sau khi sắp xếp bằng Bubble Sort
int mostFrequentBubbleSort(int arr[], int n) {
    bubbleSort(arr, n);

    int mostFrequent = arr[0], maxCount = 1, count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    return mostFrequent;
}

// 3. Sử dụng counting (mảng tần suất)
int mostFrequentCounting(int arr[], int n) {
    int countArr[MAX_VAL + 1] = {0};
    int mostFrequent = arr[0], maxCount = 0;

    for (int i = 0; i < n; i++) {
        countArr[arr[i]]++;
        if (countArr[arr[i]] > maxCount) {
            maxCount = countArr[arr[i]];
            mostFrequent = arr[i];
        }
    }

    return mostFrequent;
}

// Hàm hiển thị thời gian với đơn vị nhỏ nhất
void printTime(double time_ns) {
    if (time_ns < 1e3) {
        cout << time_ns << " ns\n";  // Hiển thị bằng ns nếu nhỏ hơn 1 µs
    } else if (time_ns < 1e6) {
        cout << time_ns / 1e3 << " µs\n";  // Hiển thị bằng µs nếu nhỏ hơn 1 ms
    } else {
        cout << time_ns / 1e6 << " ms\n";  // Hiển thị bằng ms nếu lớn hơn 1 ms
    }
}

//int main() {
//    int arr[SIZE] = {1, 3, 2, 3, 4, 1, 3, 2, 3, 5};
//    int arr1[SIZE], arr2[SIZE], arr3[SIZE];
//
//    for (int i = 0; i < SIZE; i++) {
//        arr1[i] = arr[i];
//        arr2[i] = arr[i];
//        arr3[i] = arr[i];
//    }
//
//    clock_t start, end;
//    double time_ns;
//
//    // 1. Phương pháp xác định phần tử duy nhất
//    cout << "Phương pháp 1: Xác định số lượng phần tử duy nhất, đếm số lần xuất hiện và tìm giá trị xuất hiện nhiều nhất.\n";
//    start = clock();
//    int result1 = mostFrequentUniqueElements(arr1, SIZE);
//    end = clock();
//    time_ns = (double)(end - start) * (1e9 / CLOCKS_PER_SEC);
//    cout << "Kết quả: " << result1 << " - Thời gian: ";
//    printTime(time_ns);
//    cout << endl;
//
//    // 2. Phương pháp sử dụng Bubble Sort
//    cout << "Phương pháp 2: Sắp xếp mảng bằng Bubble Sort, sau đó tìm phần tử xuất hiện nhiều nhất.\n";
//    start = clock();
//    int result2 = mostFrequentBubbleSort(arr2, SIZE);
//    end = clock();
//    time_ns = (double)(end - start) * (1e9 / CLOCKS_PER_SEC);
//    cout << "Kết quả: " << result2 << " - Thời gian: ";
//    printTime(time_ns);
//    cout << endl;
//
//    // 3. Phương pháp Bảng tần suất
//    cout << "Phương pháp 3: Sử dụng Bảng tuần suất - Đếm số lần xuất hiện của từng giá trị trong mảng.\n";
//    start = clock();
//    int result3 = mostFrequentCounting(arr3, SIZE);
//    end = clock();
//    time_ns = (double)(end - start) * (1e9 / CLOCKS_PER_SEC);
//    cout << "Kết quả: " << result3 << " - Thời gian: ";
//    printTime(time_ns);
//    cout << endl;
//
//    return 0;
//}
