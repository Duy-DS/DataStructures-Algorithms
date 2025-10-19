#include <iostream>
using namespace std;

// tạo node
struct Node {
    int info; // dữ liệu tại node
    struct Node* next; // trỏ tới địa chỉ của node tiếp theo
};

// xác định xem DSLK có phải rỗng hay không
bool isEmptyList(struct Node* node) {
    return (node == nullptr);
}

// in DSLK
void printList(struct Node* node) {
    // duyệt qua từng phần tử của DSLK
    while (node != nullptr) {
        cout << node->info << " "; // in ra giá trị của nút
        node = node->next; // tiếp tục trỏ tới nút tiếp theo
    }
    cout << endl;
}

// in địa chỉ và giá trị tương ửng cảu các node trong DSLK
void printAddressesAndValues(Node* head) {
    Node* temp = head;

    // Print the header address and data
    cout << "\nAdrress\tValue: " << endl;

    // Iterate through the list, printing the address and data of each node
    while (temp != NULL) {
        cout << temp << "\t" << temp->info << endl;
        temp = temp->next;
    }
    cout << endl;
}
// hàm xác định độ dài của DSLK
int getLength(struct Node* node) {
    int count = 0;
    // duyệt qua từng phần tử của DSLK
    while (node != nullptr) {
        count++; // đếm số phần tử
        node = node->next; // tiếp tục trỏ tới phần tử tiếp theo
    }
    return count;
}

// trả về giá trị của nút đầu tiên trong DSLK
void getFirstNode(struct Node* node) {
    cout << node->info << endl;
}
// hàm trả về giá trị của nút cuối cùng trong DSLK
void getLastNode(struct Node* node) {
    // duyệt tới khi hết DSLK
    while (node->next != nullptr) {
        node = node->next;
    }
    // in ra giá trị của nút cuối cùng
    cout << node->info << endl;
}

// hàm tìm kiếm phần tử trong DSLK
bool searchItem(struct Node* node, int& searchItem) {
    struct Node *current; // tạo con trỏ để duyệt DSLK
    bool found = false; // tạo cờ để xác định quá trình tìm kiếm

    current = node; // con trỏ chỉ tới phần tử đầu tiên
    cout << "Searching for the node " << searchItem << " in linked list" << endl;
    while (current != nullptr && !found) { // tìm kiếm trong danh sách
        if (current->info == searchItem) { // nếu tìm thấy phần tử
            found = true;
        } else { // nếu không tìm thấy
            current = current->next; // trỏ tới nút tiếp theo
        }
    }

    return found;
}
// hàm chèn nút tại vị trí đầu tiên
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node *newNode; // tạo con trỏ chỉ tới nút mới

    newNode = new Node;   // tạo nút mới

    // chèn dữ liệu
    newNode->info = new_data;
    newNode->next = (*head_ref);

    // trỏ tới địa chỉ của nút mới được chèn
    (*head_ref) = newNode;
}
// hàm chèn nút tại vị trí cuối cùng
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node; // tạo nút mới
    new_node = new Node;
    struct Node* last = *head_ref;

    // cập nhật giá trị cho nút mới
    new_node->info = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) { // nếu danh sách rỗng thì trỏ tới nút mới
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr) { // duyệt tới nút cuối cùng
        last = last->next;
    }

    last->next = new_node; // nút cuối cùng chỉ tới nút mới
    return;
}
// hàm xóa phần tử khỏi DSLK
void deleteNode(struct Node** head_ref, int key) {
    // tạo các biến tạm để lưu giá trị của phần tử cần xóa và phần tử trước nó
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // nếu phần tử cần xóa là phần tử đầu tiên
    if (temp != NULL && temp->info == key) {
        *head_ref = temp->next;
        delete temp;
        return;
    }

    // tìm phần tử cần xóa và phần tử trước nó
    while (temp != NULL && temp->info != key) {
        prev = temp;
        temp = temp->next;
    }

    // nếu không tìm thấy phần tử cần xóa
    if (temp == NULL) {
        return;
    }

    // xóa phần tử cần xóa
    prev->next = temp->next;
    delete temp;
}

// hàm sao chép DSLK
struct Node* copyList(struct Node* node) {
    struct Node* new_list = NULL;
    struct Node* tail = NULL;

    while (node != NULL) {
        // tạo nút mới
        struct Node* new_node = new Node;
        new_node->info = node->info;
        new_node->next = NULL;

        // nếu danh sách rỗng, gán nút mới làm nút đầu tiên của danh sách
        if (new_list == NULL) {
            new_list = new_node;
            tail = new_node;
        } else {
            // thêm nút mới vào cuối danh sách
            tail->next = new_node;
            tail = new_node;
        }

        // tiếp tục duyệt danh sách
        node = node->next;
    }

    // trả về danh sách mới
    return new_list;
}

void deleteLinkedList(Node** head) {
    Node* current = *head; // start from the head of the list
    Node* next;

    while (current != nullptr) {
        next = current->next; // save the next node
        delete current; // delete the current node
        current = next; // move to the next node
    }

    *head = nullptr; // update the head pointer to null
}

int main() {
    Node* head = NULL;

    // thêm nút vào DSLK
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);

    // in địa chỉ và giá trị tương ứng của nút trong DSLK
    cout << "Linked list:" << endl;
    printList(head);
    printAddressesAndValues(head);

    // tìm độ dài của DSLK
    cout << "Length: " << getLength(head) << endl << endl;

    // tìm một giá trị cụ thể trong DSLk
    int searchValue = 3;
    if (searchItem(head, searchValue)) {
        cout << "Found node with value " << searchValue << endl;
    } else {
        cout << "Node not found" << endl;
    }
    cout << endl;

    // in ra giá trị của nút đầu tiên và nút cuối cùng trong DSLk
    cout << "First node:" << endl;
    getFirstNode(head);
    cout << "Last node:" << endl;
    getLastNode(head);

    // Xóa một giá trị cụ thể trong DSLK
    int deleteValue = 3;
    deleteNode(&head, deleteValue);
    cout << "Linked list after removing " << deleteValue << ":" << endl;
    printAddressesAndValues(head);

    // chèn một giá trị cụ thể vào DSLK
    insertAtBeginning(&head, 3);
    cout << "Linked list after adding 3 back:" << endl;
    printAddressesAndValues(head);

    // sao chép DSLK
    Node* newHead = copyList(head);
    cout << "Copy of linked list:" << endl;
    printAddressesAndValues(newHead);

    // xóa toàn bộ DSLK
    deleteLinkedList(&head);

    // in địa chỉ và giá trị tương ứng của các nút trong DSLK
    cout << "Linked list after clearing:" << endl;
    printAddressesAndValues(head);

    // xóa toàn bộ DSLK
    deleteLinkedList(&newHead);

    return 0;
}

