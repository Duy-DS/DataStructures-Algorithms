#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

struct List {
	Node* head;
	Node* tail;
};

//cau a
void FindNode(List l, int x, int i) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;

	if (i == 0) {
		newNode->next = l.head;
		l.head = newNode;
	}

	Node* p = l.head;
	int count = 0;

	while (p != NULL && count < i - 1) {
		p = p->next;
		count++;
	}

	newNode->next = p->next;
	p->next = newNode;
}

//Cau b
int FindPosition(List l, int x) {
	Node* p = l.head;
	int index = 0;

	while (p != NULL) {
		if (p->data == x) return index;
		p = p->next;
		index++;
	}

	return -1;
}

int AvgList(List l) {
	Node* p = l.head;
	int sum = 0;
	int count = 0;

	while (p != NULL) {
		sum += p->data;
		p = p->next;
		count++;
	}

	return sum / count;
}