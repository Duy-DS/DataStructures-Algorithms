#include <iostream>

using namespace std;

//Cau a
struct Node {
	int key;
	Node* left;
	Node* right;
};

//Cau b
int sumTree(Node* T) {
	if (T == NULL)return 0;
	return sumTree(T->left) + sumTree(T->right) + T->key;
}

//cau c
int countTwoNode(Node* T) {
	if (T == NULL) return 0;

	int leftcount = countTwoNode(T->left);
	int rightcount = countTwoNode(T->right);

	if (T->left != NULL && T->right != NULL) {
		return leftcount + rightcount + 1;
	}

	return leftcount + rightcount;
}

//cau d
void printPath(Node* T, int k) {
	Node* cur = T;

	while (cur != NULL) {
		printf("%d ", cur->key);

		if (k == cur->key)return;
		else if (k < cur->key)
			cur = cur->left;
		else cur = cur->right;
	}
}

