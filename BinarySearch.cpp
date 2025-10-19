#include<iostream>

using namespace std;

int BinarySearch(int arr[], int length, int& item) {
	int first = 0;
	int last = length - 1;
	int mid;
	bool found = false;
	while (first <= last && !found) {
		mid = (first + last) / 2;
		if (arr[mid] == item) {
			found = true;
		}
		else if (arr[mid] > item) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}
	if (found) {
		return mid;
	}
	else {
		return -1;
	}
}

int main() {
	int arr[] = { 2, 3, 4, 10, 40 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int item;
	cout << "Enter item to search: ";
	cin >> item;
	int result = BinarySearch(arr, length, item);
	if (result != -1) {
		cout << "Element is present at index " << result << endl;
	}
	else {
		cout << "Element is not present in array" << endl;
	}
	return 0;
}