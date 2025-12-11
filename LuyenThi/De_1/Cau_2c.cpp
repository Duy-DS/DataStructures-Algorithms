#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một Node (một hạng tử)
struct Node {
    int coeff;  // Hệ số
    int exp;    // Số mũ
    Node* next; // Con trỏ trỏ tới hạng tử tiếp theo
};

// Hàm tạo một Node mới
Node* createNode(int c, int e) {
    Node* newNode = new Node();
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm một hạng tử vào cuối danh sách đa thức
// Sử dụng con trỏ tham chiếu (Node*&) để thay đổi trực tiếp head nếu cần
void addTerm(Node*& head, int c, int e) {
    Node* newNode = createNode(c, e);

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hàm cộng hai đa thức
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL; // Danh sách kết quả
    Node* p1 = poly1;
    Node* p2 = poly2;

    // Duyệt cả 2 danh sách cùng lúc
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            // Nếu mũ của p1 lớn hơn, thêm p1 vào kết quả
            addTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp) {
            // Nếu mũ của p2 lớn hơn, thêm p2 vào kết quả
            addTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else {
            // Nếu mũ bằng nhau, cộng hệ số
            int sumCoeff = p1->coeff + p2->coeff;
            // Chỉ thêm vào kết quả nếu tổng hệ số khác 0
            if (sumCoeff != 0) {
                addTerm(result, sumCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Nếu poly1 vẫn còn phần tử
    while (p1 != NULL) {
        addTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // Nếu poly2 vẫn còn phần tử
    while (p2 != NULL) {
        addTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Hàm in đa thức ra màn hình
void printPoly(Node* poly) {
    if (poly == NULL) {
        cout << "0" << endl;
        return;
    }

    Node* temp = poly;
    while (temp != NULL) {
        cout << temp->coeff << "x^" << temp->exp;
        if (temp->next != NULL) {
            cout << " + ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Tạo đa thức P(x) = 3x^3 + 5x^2 + 6
    Node* P = NULL;
    addTerm(P, 3, 3);
    addTerm(P, 5, 2);
    addTerm(P, 6, 0);

    // Tạo đa thức Q(x) = 6x^3 + 2x^1 + 1
    Node* Q = NULL;
    addTerm(Q, 6, 3);
    addTerm(Q, 2, 1);
    addTerm(Q, 1, 0);

    cout << "Da thuc P(x): ";
    printPoly(P);

    cout << "Da thuc Q(x): ";
    printPoly(Q);

    // Tính tổng
    Node* Sum = addPolynomials(P, Q);

    cout << "Tong hai da thuc: ";
    printPoly(Sum);

    return 0;
}