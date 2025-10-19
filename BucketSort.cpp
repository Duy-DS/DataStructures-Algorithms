#include<iostream>

using namespace std;

void bucketSort(float arr[], int n) {
	// Create n empty buckets
	float** buckets = new float*[n];
	int* bucketSizes = new int[n];
	for (int i = 0; i < n; i++) {
		buckets[i] = new float[n]; // Each bucket can hold up to n elements
		bucketSizes[i] = 0; // Initialize bucket sizes to 0
	}
	// Distribute input array values into buckets
	for (int i = 0; i < n; i++) {
		int bucketIndex = n * arr[i]; // Assuming arr[i] is in the range [0, 1)
		if (bucketIndex >= n) bucketIndex = n - 1; // Handle edge case
		buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
	}
	// Sort individual buckets using insertion sort
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < bucketSizes[i]; j++) {
			float key = buckets[i][j];
			int k = j - 1;
			while (k >= 0 && buckets[i][k] > key) {//s?a buckets[i][k] < key ?? th?c hi?n s?p x?p gi?m d?n
				buckets[i][k + 1] = buckets[i][k];
				k--;
			}
			buckets[i][k + 1] = key;
		}
	}
	// Concatenate all sorted buckets into arr[]
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < bucketSizes[i]; j++) {
			arr[index++] = buckets[i][j];
		}
		delete[] buckets[i]; // Free memory of each bucket
	}
	delete[] buckets; // Free memory of bucket array
	delete[] bucketSizes; // Free memory of bucket sizes array
}

int main() {
	float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
	int n = sizeof(arr) / sizeof(arr[0]);
	bucketSort(arr, n);
	cout << "Sorted array: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}