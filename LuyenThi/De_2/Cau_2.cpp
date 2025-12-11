#include <iostream>

using namespace std;

// cau b
struct Node {
	int data;
	Node* next;
};

struct Node* top = NULL;

//cau c
void push(int val) {
	struct Node* newnode;
	newnode->data = val;
	newnode->next = top;
	top = newnode;
}

//cau d
void pop() {
	if (top == NULL) cout << INT_MIN << endl;
	else {
		cout << top->data << endl;
		top = top->next;
	}
}

//cau e
void removeNegative() {
	Node* tempTop = NULL;
	while (top != NULL) {
		int x = top->data;
		Node* p = top;
		top = top->next;
		delete p;

		if (x >= 0) {
			Node* q = new Node;
			q->data = x;
			q->next = tempTop;
			tempTop = q;
		}
	}

	while (tempTop != NULL) {
		int x = tempTop->data;
		Node* p = tempTop;
		tempTop = tempTop->next;
		delete  p;

		Node* q = new Node;
		q->data = x;
		q->next = top;
		top = q;
	}
}