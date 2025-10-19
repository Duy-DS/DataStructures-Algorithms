#include<iostream>

using namespace std;

//1. Khởi tạo DSLK
struct Node {
	int info; //dữ liệu tại node
	struct Node* next; //trỏ tới địa chỉ của node tiếp theo
};

//2. xác định xem DSLK có phải rỗng khong?
bool isEmptyList(struct Node* node) {
	return (node == nullptr);
}

//3. in DSLK
void printList(struct Node* node) {
	// duyệt qua từng phần tử của DSLK
	while (node != nullptr) {
		cout << node->info << " "; //in ra gtri của nút
		node = node->next;// tiếp tục trỏ tới nút tiếp theo
	}
	cout << endl;
}

//4. Tìm độ dài của DSLK
// hàm xác định độ dài của DSLK
int getLength(struct Node* node) {
	int count = 0;
	// duyệt qua từng phần tử của DSLK
	while (node != nullptr) {
		count++; //đếm số phần tử
		node = node->next; //tiếp tục trỏ tới phần tử tiếp theo
	}
	return count;
}

// 5. Xóa DSLK
void deleteList(struct Node* node) {
	//tạo biếm tạm để lưu giá trị của phần tử cần xóa
	struct Node* temp;

	// thục hiện nếu vẫn còn nút trong DSLK
	while (node != nullptr) {
		temp = node; // lấy địa chỉ của nút
		node = node->next;// trỏ tới nút tiếp theo
		delete temp; // xóa giá trị tại địa chỉ temp
	}
}

//6. Trả về gtri của nút đầu tiên trong DSLK
void getFirstNode(struct Node* node) {
	cout << node->info << endl;
}

//7, trả về gtri của nút cuối cùng trong DSLK
void getLastNode(struct Node* node) {
	//duyệt tới khi hết mảng
	while (node->next != nullptr) {
		node = node->next;
	}
	// in ra gtri của nút cuối cùng
	cout << node->info << endl;
}

//8. Tìm kiếm phần tử trong DSLK chưa sắp xếp
bool searchItem(struct Node* node, int& searchItem) {
	struct Node* current; // tạo con trỏ để duyệt DSLK
	bool found = false;// tạo cờ để xác định quá trình tìm kiếm

	current = node;// con trỏ chỉ tới phần tử đầu tiên

	while (current != nullptr && !found)// tìm kiếm trong ds
		if (current->info == searchItem)// nếu tìm thấy phần tử
			found = true;
		else current = current->next;// trỏ tới nút tiếp theo

	return found;
}

//9.1 chèn phần tử vào vị trí đầu tiên trong DSLK
void insertAtBeginning(struct Node** head_ref, int new_data) {
	struct Node* newNode;//tạo con trỏ chỉ tới nút mới
	newNode = new Node; // tạo nút mới

	// chèn dữ liệu
	newNode->info = new_data;
	newNode->next = (*head_ref);

	// trỏ tới địa chỉ của nút mới được chèn
	(*head_ref) = newNode;
}

//9.2 Chèn phần tử vào vị trí cuối cùng trong DSLK
void insretAtEnd(struct Node** head_ref, int new_data) {
	struct Node* new_node;//tạo nút mới
	new_node = new Node;
	struct Node* last = *head_ref;
	//Cập nhật giá trị cho nút mới
	new_node->info = new_data;
	new_node->next = nullptr;

	if (*head_ref == nullptr) {// nếu ds rỗng thì trỏ tới nút mới
		*head_ref = new_node;
		return;
	}

	while (last->next != nullptr)// duyệt tới nút cuối cùng
		last = last->next;
	last->next = new_node;//nút cuối cùng chỉ tới nút mới
	return;
}

int main() {
	// khởi tạo danh sách liên kết
	struct Node* head = nullptr;

}