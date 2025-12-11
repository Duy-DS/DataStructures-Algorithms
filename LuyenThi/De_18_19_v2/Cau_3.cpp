#include<iostream>

using namespace std;


//Cau a
struct Node {
	int key;
	Node* left;
	Node* right;
};

//Cau b
Node* searchBST(Node* T, int k) {
	Node* cur = T;

	while (cur != NULL) {
		if (k < cur->key) cur = cur->left;
		else if (k > cur->key) cur = cur->right;
		else return cur;
	}

	return NULL;
}

//Cau c
Node* findmax(Node* T) {
	if (T == NULL)return NULL;

	Node* cur = T;
	while (cur->right != NULL) {
		cur = cur->right;
	}

	return cur;
}