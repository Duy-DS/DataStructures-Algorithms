#include<iostream>

using namespace std;

void heapSort(int a[], int n) {
	// xay dung max-heap
	for (int start = n / 2 - 1; start >= 0; start--) {
		int root = start;

		while (true) {
			int left = 2 * root + 1;
			int right = 2 * root + 2;
			int largest = root;

			if (left < n && a[left]>a[largest]) largest = left;

			if (right < n && a[right]>a[largest]) largest = right;

			if (largest != root) {
				swap(a[root], a[largest]);
				root = largest;
			}
			else break;
		}
	}

	for (int end = n - 1; end > 0; end--) {
		swap(a[0], a[end]);//dua max ve cuoi

		int root = 0;

		while (true) {
			int left = 2 * root + 1;
			int right = 2 * root + 2;
			int largest = root;

			if (left<end && a[left]>a[largest]) largest = left;

			if (right <end && a[right]>a[largest]) largest = right;

			if (largest != root) {
				swap(a[root], a[largest]);
				root = largest;
			}
			else break;
		}
	}
}
