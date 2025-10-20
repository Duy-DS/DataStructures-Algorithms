#include<iostream>

using namespace std;

// Define node structure
struct Node {
	int data;
	Node* next;
};

// Function to build linked list backward
Node* buildListBackward() {
	// khởi tạo giá trị của các con trỏ là nullptr
	Node* first, * newNode, * last;
	int num;
	// nhập giá trị cho danh sách liên kết
	// kết thúc việc nhập bằng việc nhập -999
	cout << "Enter a list of integers ending with -999." << endl;
	cin >> num;
	first = nullptr;
	while (num != -999) {
		//cấp phát bộ nhớ cho node và lưu trữ
		// địa chỉ của bộ nhớ được cấp phát trong newNode
		newNode = new Node;

		//sao chép gtri của biến num
		//vào biến data trong newNode
		newNode->data = num;

		//đưa newNode vào vị trí đầu tiên của danh sách
		newNode->next = first;

		//biến first trỏ đến vị trí đầu tiên của danh sách
		first = newNode;

		//đọc vào giá trị tiếp theo
		cin >> num;
	}
	return first;
}

//function print linked list
void printList(struct Node* node) {
	// duyệt qua từng phần tử của DSLK
	while (node != nullptr) {
		cout << node->data << " "; //in ra gtri của nút
		node = node->next;// tiếp tục trỏ tới nút tiếp theo
	}
	cout << endl;
}

int main() {
	Node* first = buildListBackward();
	cout << "Linked List: ";
	printList(first);

	return 0;
}
