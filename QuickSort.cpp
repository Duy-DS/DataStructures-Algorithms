#include <iostream>

using namespace std;

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high];
		int i = low - 1;
		for (int j = low; j < high; j++) {
			if (arr[j] < pivot) {
				i++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[high]);
		int pi = i + 1;
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void quickSort2(int arr[], int first, int last) {
	int lower = first + 1, upper = last;
	swap(arr[first], arr[(first + last) / 2]);
	int pivot = arr[first];
	while (lower <= upper) {
		while (pivot > arr[lower]) lower++;
		while (pivot < arr[upper]) upper--;
		if (lower < upper)
			swap(arr[lower++], arr[upper--]);
		else lower++;
	}
	swap(arr[first], arr[upper]);
	if (first < upper - 1)
		quickSort2(arr, first, upper - 1);
	if (upper + 1 < last)
		quickSort2(arr, upper + 1, last);
}

void quickSort3(int arr[], int left, int right) {
	if (left < right) {
		// pi is where the pivot is at
		int pi = partition(arr, left, right);
		// Separately sort elements before and after partition 
		quickSort(arr, left, pi - 1);
		quickSort(arr, pi + 1, right);
	}
} 
int choosePivot(int left, int right) {
	return left + (right - left) / 2;
}
int partition(int arr[], int left, int right) {
	int pivotInd = choosePivot(left, right); // Index of pivot
	swap(arr[right], arr[pivotInd]); // put the pivot at the end
	int pivot = arr[right]; // Pivot 
	int i = (left - 1); // All the elements less than or equal to the
	// pivot go before or at i
	for (int j = left; j <= right - 1; j++) {
		if (arr[j] <= pivot) {
			i++; // increment the index 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[right]); // Putting the pivot back in place
	return (i + 1);
}


int main() {
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort2(arr, 0, n - 1);
	cout << "Sorted array: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}