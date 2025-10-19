#include<iostream>

using namespace std;

int LinearSearch(int arr[], int length, int& item) {
	int loc;
	bool found = false;
	loc = 0;
	while (loc < length && !found) {
		if (arr[loc] == item) {
			found = true;
		}
		else {
			loc++;
		}
	}
	if (found) return loc;
	else return -1;
}

int	main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int item;
	cout << "Enter the item to be searched: ";
	cin >> item;
	int result = LinearSearch(arr, length, item);
	if (result != -1) {
		cout << "Item found at index: " << result << endl;
	}
	else {
		cout << "Item not found in the array." << endl;
	}
	return 0;
}