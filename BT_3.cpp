#include<iostream>

using namespace std;
int main() {
	//1. khai bao kich thuoc
	int maxCol = 2;
	int maxRow = 4;
	int arr[4][2] = { 0 };
	//2. nhap du lieu
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			cout << "Nhap phan tu arr[" << i << "][" << j << "] : ";
			cin >> arr[i][j];
		}
	}
	
	//3. xuat du lieu
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

}