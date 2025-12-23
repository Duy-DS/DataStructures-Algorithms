#include <iostream>

using namespace std;

//Cau a
struct Triangle {
	int x;
	int y;
	int z;
};

struct Node {
	Triangle data;
	Node* next;
};

//Cau b
void Insert(Node*& Head, Triangle a) {
	Node* newNode = new Node;
	newNode->data = a;
	newNode->next = NULL;

	int sumA = a.x + a.y + a.z;

	if (Head == NULL || 
		newNode->data.x + newNode->data.y + newNode->data.z >= sumA) {
		newNode->next = Head;
		Head = newNode;
		return;
	}

	Node* curr = Head;
	while (curr->next != NULL) {
		int sumNext = curr->next->data.x +
			curr->next->data.y +
			curr->next->data.z;
		if (sumNext >= sumA) break;
		curr = curr->next;
	}

	newNode->next = curr->next;
	curr->next = newNode;
}

//Cau c
int count(Node* Head) {
	int count = 0;
	Node* p = Head;

	while (p != NULL) {
		int x = p->data.x;
		int y = p->data.y;
		int z = p->data.z;

		if (x + y > z && x + z > y && z + y > x) count++;
		p = p->next;
	}

	return count;
}

//Cau d
void Delete(Node*& Head) {
	Node* temp;

	while (Head != NULL) {
		temp = Head;
		Head = Head->next;
		delete temp;
	}
}