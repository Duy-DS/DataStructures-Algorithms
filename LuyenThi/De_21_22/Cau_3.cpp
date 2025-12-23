#include<iostream>

using namespace std;

//cau c
struct Node {
	double key;
	Node* left;
	Node* right;
};

//cau d
int countLeaf(Node* T) {
	if (T == NULL)return 0;
	if (T->left == NULL && T->right != NULL ||
		T->left != NULL && T->right == NULL) {
		return 1;
	}

	return countLeaf(T->left) + countLeaf(T->right);
}

double ratioLeaf(Node* T) {
	if (T == NULL)return 0;

	int leftLeaf = countLeaf(T->left);
	int rightLeaf = countLeaf(T->right);

	if (leftLeaf == 0) {
		if (rightLeaf == 0) return 0;
		return 0;
	}
	return (double)leftLeaf / rightLeaf;
}