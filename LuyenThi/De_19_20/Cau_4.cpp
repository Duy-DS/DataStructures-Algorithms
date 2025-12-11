#include<iostream>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

//Cau_a_v1
int countnodele(Node* T) {
	if (T == NULL) {
		return 0;
	}

	int leftcount = countnodele(T->left);
	int rightcount = countnodele(T->right);

	if (T->data % 2 != 0) {
		return leftcount + rightcount + 1;
	}

	return leftcount + rightcount;
}

//Cau_a_v2
int countNodeLe(Node* T) {
	if (T == NULL)return 0;

	int isOdd = (T->data % 2 != 0) ? 1 : 0;

	return isOdd + countNodeLe(T->left) + countNodeLe(T->right);
}

//Cau_b
int countOneChildNode(Node* T) {
	if (T == NULL)return 0;

	int leftcount = countOneChildNode(T->left);
	int rightcount = countOneChildNode(T->right);

	if ((T->left != NULL && T->right == NULL) || (T->left == NULL && T->right != NULL))
		return 1 + leftcount + rightcount;

	return leftcount + rightcount;
}

//Cau_c
int countNodesInInterval(Node* T, int x, int y) {
	if (T == NULL)return 0;

	if (T->data <= y)return countNodesInInterval(T->left, x, y);
	if (T->data >= x)return countNodesInInterval(T->right, x, y);

	return 1 + countNodesInInterval(T->left, x, y) + countNodesInInterval(T->right, x, y);
}