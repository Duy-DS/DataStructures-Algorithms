#include <iostream>

using namespace std;

//Cau a
struct Node {
	int key;
	Node* left;
	Node* right;
};

Node* T = NULL;

//Cau b
int countTwoNode(Node* T) {
	if (T == NULL) { return 0; }

	int leftcount = countTwoNode(T->left);
	int rightcount = countTwoNode(T->right);

	//ktra nút có đủ hai con
	if (T->left != NULL && T->right != NULL) {
		return leftcount + rightcount + 1;
	}

	return leftcount + rightcount;
}

//Cau c
int findlevel(Node* T, int k) {
	int level = 1;
	Node* p = T;

	while (p != NULL) {
		if (p->key < k) {
			p = p->right;
		}
		else if (p->key > k) {
			p = p->left;
		}
		else return level;

		level++;
	}
	return -1;// không tìm thấy
}

// câu d
int demnutchan(Node* T) {
	if (T == NULL) return 0;

	int leftcount = demnutchan(T->left);
	int rightcount = demnutchan(T->right);

	if (T->key % 2 == 0) {
		return leftcount + rightcount + 1;
	}

	return leftcount + rightcount;
}