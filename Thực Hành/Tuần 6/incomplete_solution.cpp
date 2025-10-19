// Linked list operations in C++
#include <iostream>
using namespace std;

// tạo node
struct Node {
    int info; // dữ liệu tại node
    struct Node* next; // trỏ tới địa chỉ của node tiếp theo
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory to a node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // insert the data
    new_node->info = new_data;
    new_node->next = (*head_ref);

    // Move head to new node
    (*head_ref) = new_node;
}

// Insert at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; /* used in step 5*/

    new_node->info = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr) last = last->next;

    last->next = new_node;
    return;
}

// Sort the linked list
void sortLinkedList(struct Node** head_ref) {
    struct Node *current = *head_ref, *index = nullptr;
    int temp;

    if (head_ref == nullptr) {
        return;
    } else {
        while (current != nullptr) {
            // index points to the node next to current
            index = current->next;

            while (index != nullptr) {
                if (current->info > index->info) {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

// Print the linked list
void printList(struct Node* node) {
    while (node != nullptr) {
        cout << node->info << " ";
        node = node->next;
    }
    cout << endl;
}

void getFirstNode(struct Node* node) {
    cout << node->info << endl;
}

void getLastNode(struct Node* node) {
    while (node->next != nullptr) {
        node = node->next;
    }
    cout << node->info << endl;
}

int main() {
    // khởi tạo danh sách liên kết
    struct Node* head = nullptr;

    // nhập dữ liệu cho danh sách liên kết
    int num;
    cout << "Enter numbers ending with -999" << endl;
    cin >> num;
    while (num != -999)
    {
        insertAtEnd(&head, num);
        cin >> num;
    }

    // in ra danh sách liên kết vừa nhập
    cout << "Linked list: ";
    printList(head);

    // in ra giá trị của node đầu tiên
    cout << "First node ";
    getFirstNode(head);

    // in ra giá trị của node cuối cùng
    cout << "Last node ";
    getLastNode(head);

    sortLinkedList(&head);
    cout << "\nSorted List: ";
    printList(head);
}