#include<iostream>

using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

//cau b
Node* insterBST(Node* T, int x) {
	if (T == NULL) {
		Node* newNode = new Node;
		newNode->key = x;
		newNode->left = newNode->right = NULL;
		return newNode;
	}

	if (x < T->key)
		T->left = insterBST(T->left, x);
	else if (x > T->key)
		T->right = insterBST(T->right, x);
	else return T;

	return T;
}

//Cau c
int countLeaf(Node* T) {
	if (T == NULL)return 0;
	if (T->left == NULL && T->right == NULL)return 1;

	return countLeaf(T->left) + countLeaf(T->right);
}