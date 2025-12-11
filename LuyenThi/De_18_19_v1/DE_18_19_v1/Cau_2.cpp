#include <iostream>

using namespace std;

//Cau a
struct phanSo { //ĐN cấu trức phân số
	int tuso;
	int mauso;
};

struct Node // ĐN cấu trúc một nút trong ds
{
	phanSo ps;
	Node* next;
};

struct List
{
	Node* head;
	Node* tail;
};

// Hàm khởi tạo (nên có để tránh lỗi rác bộ nhớ)
void initList(List& l) {
	l.head = l.tail = NULL;
}

// Hàm thêm vào cuối (để tạo dữ liệu test)
void addTail(List& l, int tu, int mau) {
	Node* p = new Node;
	p->ps.tuso = tu;
	p->ps.mauso = mau;
	p->next = NULL;

	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else {
		l.tail->next = p;
		l.tail = p;
	}
}

//Cau b
Node* findMaxFraction(List& list) {
	if (list.head == NULL)return NULL;

	Node* maxNode = list.head;
	Node* cur = list.head->next;

	while (cur != NULL) {
		long long tich1 = (long long)cur->ps.tuso * maxNode->ps.mauso;
		long long tich2 = (long long)cur->ps.mauso * maxNode->ps.tuso;

		if (tich1 > tich2) {
			maxNode = cur;
		}
		cur = cur->next;
	}
	return maxNode;
}

//cau c
int dempstrongkhoang0_1(List list) {
	int count = 0;
	Node* cur = list.head;

	while (cur != NULL) {
		if (cur->ps.tuso < cur->ps.mauso) {
			count++;
		}

		cur = cur->next;
	}
	return count;
}