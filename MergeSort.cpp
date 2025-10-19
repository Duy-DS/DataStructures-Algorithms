#include<iostream>

using namespace std;
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // C?p phát m?ng t?m
    int* L = new int[n1];
    int* R = new int[n2];

    // Sao chép d? li?u sang m?ng t?m
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Ch? s? hi?n t?i c?a t?ng m?ng con và m?ng g?p
    int i = 0;      // ch? s? m?ng L
    int j = 0;      // ch? s? m?ng R
    int k = left;   // v? trí hi?n t?i trong m?ng arr

    // Tr?n 2 m?ng con vào arr
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {  // ??i ?i?u ki?n: >= ?? s?p x?p gi?m d?n và v?n ?n ??nh
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Sao chép ph?n còn l?i c?a L (n?u còn)
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Sao chép ph?n còn l?i c?a R (n?u còn)
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    // Gi?i phóng b? nh?
    delete[] L;
    delete[] R;
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		// m is the point where the array is divided into two subarrays
		int m = left + (right - left) / 2;

        mergeSort(arr, left, m);
		mergeSort(arr, m + 1, right);

		// Merge the sorted subarrays
		merge(arr, left, m, right);
	}
}

// Ví d? ch?y th?
int main() {
    int arr[] = { 9, 4, 7, 3, 10, 5, 2, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    cout << "Mang da sap xep: ";
    for (int x : arr) cout << x << ' ';
    cout << '\n';
    return 0;
}