#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Hàm tạo nút mới
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Hàm chèn phần tử vào cây
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Hàm tìm kiếm phần tử trong cây
Node* search(Node* root, int data) {
    if (root == nullptr || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Hàm tìm nút có giá trị nhỏ nhất trong cây con phải của một nút
Node* findMin(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Hàm xóa phần tử khỏi cây
Node* remove(Node* root, int data) {
    // Trường hợp 1: Cây rỗng hoặc không tìm thấy nút cần xóa
    if (root == nullptr) return root; // Trả về root (nullptr) nếu cây rỗng hoặc không tìm thấy data

    // Trường hợp 2: Giá trị cần xóa nhỏ hơn giá trị nút hiện tại
    if (data < root->data)
        root->left = remove(root->left, data); // Đệ quy xóa ở cây con trái
        // Trường hợp 3: Giá trị cần xóa lớn hơn giá trị nút hiện tại
    else if (data > root->data)
        root->right = remove(root->right, data); // Đệ quy xóa ở cây con phải
        // Trường hợp 4: Tìm thấy nút cần xóa (root->data == data)
    else {
        // Trường hợp 4.1: Nút cần xóa chỉ có cây con phải hoặc không có cây con nào
        if (root->left == nullptr) {
            Node* temp = root->right; // temp lưu trữ cây con phải (hoặc nullptr)
            delete root; // Xóa nút hiện tại
            return temp; // Trả về cây con phải (hoặc nullptr) để thay thế nút đã xóa
        }
            // Trường hợp 4.2: Nút cần xóa chỉ có cây con trái
        else if (root->right == nullptr) {
            Node* temp = root->left; // temp lưu trữ cây con trái
            delete root; // Xóa nút hiện tại
            return temp; // Trả về cây con trái để thay thế nút đã xóa
        }
        else {
            // Trường hợp 4.3: Nút cần xóa có cả cây con trái và phải
            // Tìm nút có giá trị nhỏ nhất trong cây con phải (successor)
            Node *temp = findMin(root->right);
            // Thay thế giá trị của nút cần xóa bằng giá trị của successor
            root->data = temp->data;
            // Xóa successor khỏi cây con phải (đệ quy)
            root->right = remove(root->right, temp->data);
        }
    }
    // Trả về root sau khi xóa (hoặc không xóa nếu không tìm thấy)
    return root;
}

// Hàm duyệt cây theo thứ tự trước
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Hàm duyệt cây theo thứ tự giữa
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Hàm duyệt cây theo thứ tự sau
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

// Hàm in cây nhị phân (trực quan hóa)
void printTree(Node* root, int space) {
    if (root == nullptr) {
        return;
    }

    space += 8; // Khoảng cách giữa các mức

    printTree(root->right, space);

//    std::cout << std::endl;
    for (int i = 10; i < space; i++) {
        std::cout << " ";
    }
    std::cout << root->data << std::endl;

    printTree(root->left, space);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    std::cout << "Binary Search Tree:" << std::endl;
    printTree(root, 0);

    std::cout << "Preorder traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    Node* searchResult = search(root, 40);
    if (searchResult) {
        std::cout << "Found node: " << searchResult->data << std::endl;
    } else {
        std::cout << "Node not found." << std::endl;
    }

    root = remove(root, 40);

    std::cout << "Inorder traversal after removing 40: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}