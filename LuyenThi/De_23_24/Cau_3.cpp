#include<iostream>

using namespace std;

//Cau_a
struct Word {
	string sa;
	string sv;
};

struct Node {
	Word data;
	Node* left;
	Node* right;
};

//Cau b
void Insert(Node*& T, Word w) {
	Node* newNode = new Node;
	newNode->data = w;
	newNode->left = NULL;
	newNode->right = NULL;
	T = newNode;
	return;

	if (w.sa < T->data.sa) Insert(T->left, w);
	else if (w.sa > T->data.sa)Insert(T->right, w);

}
//Cau c
//Cach 1
string Search_v1(Node* T, string sa) {
	if (T == NULL) return "";

	while (T != NULL) {

		if (sa > T->data.sa)
			Search_v1(T->right, sa);
		else if (sa < T->data.sa)
			Search_v1(T->left, sa);
		else
			return T->data.sv;
	}
}
//Cach 2
string Search_v2(Node* T, string sa) {
	while (T != NULL) {
		if (sa > T->data.sa)
			T = T->right;
		else if (sa < T->data.sa)
			T = T->left;
		else return T->data.sv;
	}
	return "";
}

//Cau d
void print(Node* T) {
	if (T != NULL) {
		print(T->left);
		cout << T->data.sa << " : " << T->data.sv << endl;
		print(T->right);
	}
}

int main() {
	Node* Root = NULL;

	// Chèn dữ liệu không theo thứ tự
	Insert(Root, { "love", "yeu" });
	Insert(Root, { "hate", "ghet" });
	Insert(Root, { "apple", "qua tao" });
	Insert(Root, { "zoo", "so thu" });
	Insert(Root, { "cat", "con meo" });

	cout << "Danh sach tu vung (Tang dan):" << endl;
	print(Root);

	return 0;
}