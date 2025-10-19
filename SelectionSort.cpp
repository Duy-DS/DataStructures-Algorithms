#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(arr[i], arr[minIndex]);
		}
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	cout << "Nhap so luong phan tu trong mang: ";
	int n;
	cin >> n;
	int* arr = new int[n];
	cout << "Nhap cac phan tu trong mang: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	selectionSort(arr, n);
	printArray(arr, n);
	delete[] arr;
}