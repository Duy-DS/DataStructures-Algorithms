//#include <iostream>
//using namespace std;
//
//// Define node structure
//struct Node {
//    int data;
//    Node* next;
//};
//
//// Function to build linked list forward
//Node* buildListForward() {
//    Node *first, *newNode, *last;
//    int num;
//    cout << "Enter a list of integers ending with -999:" << endl;
//    cin >> num;
//    first = nullptr;
//    while (num != -999) {
//        newNode = new Node;
//        newNode->data = num;
//        newNode->next = nullptr;
//
//        if (first == nullptr) {
//            first = newNode;
//            last = newNode;
//        } else {
//            last->next = newNode;
//            last = newNode;
//        }
//        cin >> num;
//    }
//    return first;
//}
//
//// Function to print linked list
//void printList(Node* first) {
//    Node* current = first;
//    while (current != nullptr) {
//        cout << current->data << " ";
//        current = current->next;
//    }
//    cout << endl;
//}
//
//// Function to get length of linked list
//int getListLength(Node* first) {
//    int length = 0;
//    Node* current = first;
//    while (current != nullptr) {
//        length++;
//        current = current->next;
//    }
//    return length;
//}
//
//// Function to print first node value
//void printFirstNode(Node* first) {
//    if (first != nullptr)
//        cout << "First node value: " << first->data << endl;
//    else
//        cout << "List is empty." << endl;
//}
//
//// Function to print last node value
//void printLastNode(Node* first) {
//    if (first == nullptr) {
//        cout << "List is empty." << endl;
//        return;
//    }
//    Node* current = first;
//    while (current->next != nullptr) {
//        current = current->next;
//    }
//    cout << "Last node value: " << current->data << endl;
//}
//
//int main() {
//    Node* first = buildListForward();
//    cout << "Linked List: ";
//    printList(first);
//    cout << "List Length: " << getListLength(first) << endl;
//    printFirstNode(first);
//    printLastNode(first);
//    return 0;
//}
