#include<iostream>

using namespace std;

//cau a
struct Node {// Định nghĩa cấu trúc của một Nút (Node)
	int data;
	Node* next;
};

struct List {// Định nghĩa cấu trúc danh sách liên kết (List)
	Node* head;
	Node* tail;
};

// Hàm khởi tạo danh sách rỗng (Bắt buộc phải có khi dùng DSLK)
void Init(List& l) {
	l.head = l.tail = NULL;
}
//chền một đối tượng có giá trị k vào đầu của DSLK
//cach 1
void insertHead(List l, int k) {
	Node* newNode = new Node;

	newNode->data = k;
	newNode->next = l.head;

	l.head = newNode;
}

//cach 2
Node* CreateNode(int k) {
	Node* p = new Node; // Cấp phát bộ nhớ động
	if (p == NULL) {
		return NULL; // Hết bộ nhớ, không tạo được
	}
	p->data = k;     // Gán giá trị k vào phần dữ liệu
	p->next = NULL; // Mặc định chưa trỏ đi đâu cả
	return p;
}

void AddHead(List& l, int k) {
	// 1. Tạo nút mới
	Node* p = CreateNode(k);
	if (p == NULL) return; // Nếu không tạo được nút thì dừng

	// 2. Trường hợp danh sách rỗng
	if (l.head == NULL) {
		l.head = l.tail = p; // Đầu và đuôi đều là p
	}
	// 3. Trường hợp danh sách đã có phần tử
	else {
		p->next = l.head; // B1: Móc dây của p vào thằng đầu cũ
		l.head= p;        // B2: Cập nhật lại biển hiệu "Đầu danh sách" là p
	}
}

//Cau b
void insertTail(List l, int k) {
	Node* newNode = new Node;
	newNode->data = k;
	newNode->next = NULL;

	if (l.head == NULL) l.head = l.tail = newNode;
	else {
		l.tail->next = newNode;
		l.tail = newNode;
	}
}

//cau c
Node* findMaxNode(List l) {
	Node* maxNode = NULL;
	Node* cur = l.head;

	while (cur != NULL) {
		if (cur->data % 2 == 0) {
			if (maxNode == NULL || cur->data > maxNode->data) {
				maxNode = cur;
			}
		}
		cur = cur->next;
	}
	return maxNode;
}