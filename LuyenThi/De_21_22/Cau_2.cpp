#include<iostream>

using namespace std;

//Cau a
struct Node {
	double data;
	Node* next;
};

struct List {
	Node* head;
	Node* tail;
};

//Cau b
double TimSoNhoThuHai(List l) {
	Node* p = l.head;
	if (p == NULL || p->next == NULL) return DBL_MAX;

	double min1 = DBL_MAX;
	double min2 = DBL_MAX;

	while (p != NULL) {
		double x = p->data;
		if (x < min1) {
			min2 = min1;
			min1 = x;
		}
		else if (x > min1 && x < min2) {
			min2 = x;
		}
		p = p->next;
	}

	if (min2 == DBL_MAX) return min2;
	return min2;
}

//Cau c
void printValueBigger(List l, double k) {
	Node* p = l.head;

	bool found = false;

	while (p != NULL) {
		if (p->data > k) {
			cout << p->data << endl;
			found = true;
		}
		p = p->next;
	}

	if (found = false)cout << "Ko co gia tri nao";
}

//Cau d
void removeNodesSmaller(List l, double k) {
	while (l.head != NULL && l.head->data < k) {
		Node* temp = l.head;
		l.head = l.head->next;
		delete temp;
	}

	if (l.head == NULL) {
		l.tail = NULL;
		return;
	}

	Node* prev = l.head;
	Node* curr = l.head->next;
	while (curr != NULL) {
		if (curr->data < k) {
			prev->next = curr->next;
			delete curr;
			curr = prev->next;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
}