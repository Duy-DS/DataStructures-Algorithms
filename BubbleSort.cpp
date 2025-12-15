#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
	// lap tat ca cac phan tu trong mang
	// ngoai tru phan tu cuoi cung
	for (int i = 0; i < n - 1; i++) {
		// so sanh v?i phan tu chua duoc sap xep
		for (int j = 0; j < n - i - 1; j++) {
			//neu phan tu hien tai lon hon phan tu ke tiep
			// thi doi cho hai phan tu
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void BubbleSort_Recursive(int arr[], int n){
	//dieu kien dung: neu chi con 1 phan tu thi dung
	if(n==1) return;
	//thuc hien 1 luot bubble
	for(int i=0; i<n-1; i++){
		if(arr[i]>arr[i+1])
			swap(arr[i], arr[i+1]);
	}
	//goi de quy
	BubbleSort_Recursive(a, n-1);
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
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
	bubbleSort(arr, n);
	printArray(arr, n);
	delete[] arr;


}
