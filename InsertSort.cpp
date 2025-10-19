#include <iostream>

using namespace std;

void insertion_sort(int arr[], int n) {
	// lap tat ca cac phan tu trong mang
	for (int i = 0; i < n; i++) {
		// luu phan tu hien tai vao mot gia tri
		int value = arr[i];
		// so sanh phan tu hien tai voi cac phan tu truoc do
		int j = i - 1;
		// dich chuyen phan tu sang ben phai 
		// cho den khi tim duoc vi tri thich hop
		while (j >= 0 && arr[j] > value) {
			arr[j + 1] = arr[j];
			j--;
		}
		// chen phan tu hien tai vao vi tri thich hop
		arr[j + 1] = value;
	}
}

int main() {
	int n;
	cout << "Nhap so luong phan tu trong mang: ";
	cin >> n;
	int* arr = new int[n]; //mang dong
	//int arr[n]; n phai la hang so nguyen duong
	cout << "Nhap cac phan tu trong mang: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	insertion_sort(arr, n);
	cout << "Mang sau khi sap xep la: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	delete[] arr; //giai phong bo nho cap phat dong
	return 0;
}
