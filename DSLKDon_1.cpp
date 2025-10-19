#include<iostream>

using namespace std;

// B??c 1: Định ngh?a c?u trúc Node
struct Node
{
	int data;
	Node* pNext;//d?u sao là ch? ??i t??ng sau

};

//B??c 2: c?p phát ??ng Node ?? qu?n lý giá tr? c?n l?u(xin kh?i t?o Node)
Node* initNode(int value) {
	Node* p = new Node;

	p->data = value;
	p->pNext = NULL;

	return p;
}

//B??c 3: ??nh ngh?a danh sách List
struct List{
	Node* pHead;
	Node* pTail;
};

//B??c 4: Kh?i t?o List
void initList(List& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

void addHead(List& l, Node* p) {
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void addTail(List& l, Node* p) {
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void printListFor(List l)
{
	for (Node* p = l.pHead; p != NULL; p = p->pNext) {
		cout << p->data << " ";
	}
	cout << endl;
}

void printListWh(List l)
{
	Node* p = l.pHead;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->pNext;
	}
}

int main() {

	List l;
	initList(l);//g?i nó là l r?ng

	//10     79     39
	Node* p1 = initNode(10);
	Node* p2 = initNode(79);
	Node* p3 = initNode(39);

	addHead(l, p1);
	addTail(l, p2);
	addTail(l, p3);

	printListFor(l);
	printListWh(l);

	addHead(l, initNode(5));
	addHead(l, initNode(50));

	printListFor(l);
	printListWh(l);

	return 0;
}