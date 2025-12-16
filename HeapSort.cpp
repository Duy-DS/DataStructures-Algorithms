#include<iostream>

using namespace std;

void heapSort(int a[], int n) {
	// xay dung max-heap -> phần tử lớn nhất luôn nằm ở gốc (a[0])
	for (int start = n / 2 - 1; start >= 0; start--) {
		// Vì sao bắt đầu từ n/2 - 1?; Các phần tử từ n/2 → n-1 là lá -> Lá đã là heap -> Ta chỉ cần heapify các nút cha
		int root = start; //root là nút đang xét, ta sẽ đẩu nó xuống đúng vị trí trong heap

		while (true) {//Lặp cho đến khi root đã đúng vị trí
			int left = 2 * root + 1;//con trái
			int right = 2 * root + 2;//con phải
			int largest = root;//Giả sử root là lớn nhất

			//Kiểm tra con trái có tồn tại không, nếu con trái lớn hơn root -> chọn con trái
			if (left < n && a[left]>a[largest]) largest = left;
			
			//Kiểm tra con phải có tồn tại không, nếu con phải lớn hơn root -> chọn con phải
			if (right < n && a[right]>a[largest]) largest = right;

			if (largest != root) {//Nếu root KHÔNG lớn nhất → đổi chỗ
				swap(a[root], a[largest]);
				root = largest;
			}
			else break;
		}
	}

	//Sắp xếp bằng cách lấy max
	for (int end = n - 1; end > 0; end--) {
		swap(a[0], a[end]);//lấy max a(a[0]) dua max ve cuoi

		int root = 0;//khôi phục heap cho phần còn lại; Heap lại bắt đầu từ gốc

		while (true) {//Heapify lại (giống phần trên)
			int left = 2 * root + 1;
			int right = 2 * root + 2;
			int largest = root;

			if (left<end && a[left]>a[largest]) largest = left; //left < end: Không xét phần đã sắp xếp

			if (right <end && a[right]>a[largest]) largest = right;//left < end: Không xét phần đã sắp xếp

			if (largest != root) {
				swap(a[root], a[largest]);
				root = largest;
			}
			else break;
		}
	}
}

