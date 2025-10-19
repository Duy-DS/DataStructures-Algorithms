#include<iostream>
#include<Windows.h>

using namespace std;

void countingSort(int arr[], int n) {
	int maxVal = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
	}
	int* count = new int[maxVal + 1]();
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}
	int index = 0;
	for (int i = 0; i <= maxVal; i++) {
		while (count[i] > 0) {
			arr[index++] = i;
			count[i]--;
		}
	}
	delete[] count;
}

void countingSort_2(int arr[], int n) {
	// Tim gia tri lon nhat trong mang
	int max_element = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max_element) {
			max_element = arr[i];
		}
	}

	// Tao mang dem voi tat ca cac phan tu khoi tao bang 0
	int* count = new int[max_element + 1]();

	// Dem so lan xuat hien cuar moi phan tu duy nhat 
	// va luu tru trong mang dem
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	// Tim tong tich luy va luu no truc tiep vao mang count
	for (int i = 1; i <= max_element; i++) {
		count[i] += count[i - 1];
	}

	// Khoi phuc cac phan tu vao mang va giam so luong 
	// cua tung phan tu duoc khoi phuc xuong 1
	int* sorted_array = new int[n];
	for (int i = n - 1; i >= 0; i--) {
		sorted_array[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	//sao chep mang da sx vao mang ban dau
	for (int i = 0; i < n; i++) {
		arr[i] = sorted_array[i];
	}
	// Gi?i phóng b? nh?
	delete[] count;
	delete[] sorted_array;
}

void CountFrequency(int arr[], int n, int count[]) {
	if (n == 0) return;
	count[arr[n - 1]]++;
	CountFrequency(arr, n - 1, count);
}

void cumulativeCount(int count[], int i, int max_val) {
	if (i > max_val) return;
	count[i] += count[i - 1];
	cumulativeCount(count, i + 1, max_val);
}

void buildOutput(int arr[], int n, int count[], int output[]) {
	if (n == 0) return;
	int value = arr[n - 1];
	output[count[value] - 1] = value;
	count[value]--;
	buildOutput(arr, n - 1, count, output);
}

void CountingSort_Recursive(int arr[], int n) {
	int max_val = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max_val) max_val = arr[i];

	int* count = new int[max_val + 1]();
	int * output = new int[n];

	CountFrequency(arr, n, count);
	cumulativeCount(count, 1, max_val);
	buildOutput(arr, n, count, output);

	for (int i = 0; i < n; i++)
		arr[i] = output[i];
	
	delete[] count;
	delete[] output;
}

int main() {
	// Thi?t l?p mã hóa UTF-8 cho ??u vào và ??u ra trên Windows
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int arr[] = { 4, 2, 2, 8, 3, 3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	CountingSort_Recursive(arr, n);
	cout << "Sorted array: \n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}