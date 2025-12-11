#include<iostream>
#include<algorithm>

using namespace std;

void timCapSoGanNhat(int arr[]) {
	int n = arr.size();

	sort(arr.begin(), arr.end());

	int min_diff = INT_MAX;
	int num1, num2;

	for (int i = 0; i < n - 1; i++) {
		int cur_diff = arr[i + 1] - arr[i];

		if (cur_diff < min_diff) {
			min_diff = cur_diff;
			num1 = arr[i];
			num2 = arr[i + 1];
		}
	}
	cout << num1 << num2 << endl;
	cout << min_diff;
}