#include<iostream>

using namespace std;

//Cau a
struct Node {
	int data;
	Node* next;
};

struct List
{
	Node* head;
	Node* tail;
};

bool isprime(int n) {
	if (n < 2)return false;
	if (n == 2)return true;
	for (int i = 3; i < sqrt(n); i + 2) {
		if (n % i == 0) return false;
	}
	return true;
}

void countprimes(List l) {
	Node* p = l.head;
	int count = 0;

	while (p != NULL) {
		if (isprime(p->data)) count++;
	}
	p = p->next;
}

//Cau b
void sortList(List l) {
	for (Node* p = l.head; p != NULL; p = p->next) {
		for (Node* q = p->next; q != NULL; q = q->next) {
			if (p->data > q->data) {
				swap(p->data, q->data);
			}
		}
	}
}