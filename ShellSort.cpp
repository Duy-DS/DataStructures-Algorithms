#include <iostream>

using namespace std;

/*
* Ý t??ng cho s?p x?p t?ng d?n m?t m?ng có N ph?n t?.
 • T??ng t? nh? shell sort b?ng cách chia m?ng ban ??u thành các m?ng con, s?p 
x?p chúng riêng bi?t và sau ?ó chia chúng m?t l?n n?a ?? s?p x?p các m?ng con 
m?i cho ??n khi toàn b? m?ng ???c s?p x?p. 
• M?ng ban ??u ???c chia thành hai m?ng con, m?ng ??u ch?a các giá tr? nh? h?n 
giá tr? pivot và m?ng sau ch?a các giá tr? l?n h?n ho?c b?ng giá tr? pivot.
 • Quá trình ???c l?p l?i v?i các m?ng con
*/

void ShellSort(int arr[], int n) {
	int i, j, hCnt, h;
	int increments[20], k;
	// t?o m?t s? gia s? h thích h?p
	for (h = 1, i = 0; h < n; i++) {
		increments[i] = h;
		h = 3 * h + 1;
	}

	//vòng l?p trên s? l??ng các b??c t?ng khác nhau h
	for (i--; i >= 0; i--) {
		h = increments[i];
		//vòng l?p trên s? l??ng các m?ng con ???c s?p x?p h trong l?n l?p th? i
		for (hCnt = h; hCnt < n; hCnt++) {
			//s?p x?p chèn cho m?ng con ch?a m?i ph?n t? th? h
			for (j = hCnt; j < n;) {
				int tmp = arr[j];
				k = j;
				while (k - h >= 0 && tmp < arr[k - h]) {
					arr[k] = arr[k - h];
					k -= h;
				}
				arr[k] = tmp;
				j += h;
			}
		}
	}
}

void ShellSort2(int arr[], int n) {
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2) {
		// Do a gapped insertion sort for this gap size.
		// The first gap elements arr[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is gap sorted
		for (int i = gap; i < n; i += 1) {
			// add arr[i] to the elements that have been gap sorted
			// save arr[i] in temp and make a hole at position i
			int temp = arr[i];
			// shift earlier gap-sorted elements up until the correct location for arr[i] is found
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			// put temp (the original arr[i]) in its correct location
			arr[j] = temp;
		}
	}
}

int main() {
	int arr[] = { 12, 34, 54, 2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, n);
	cout << "Sorted array: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}