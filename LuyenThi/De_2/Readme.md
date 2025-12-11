# ĐỀ THI CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT - ĐỀ 2
*(Sinh viên KHÔNG ĐƯỢC sử dụng tài liệu)*

### Câu 1. (2,0 điểm)
a. Viết giải thuật sắp xếp một mảng các số nguyên theo thứ tự **giảm dần** sử dụng thuật toán **sắp xếp chọn (selection sort)**.

b. Minh họa nguyên lý hoạt động của thuật toán sắp xếp chọn để sắp xếp chuỗi các số nguyên sau $\{1, 2, 3, 1, 4, 4, 1\}$ theo thứ tự **giảm dần**.

---

### Câu 2. (4,0 điểm)
a. Phát biểu định nghĩa và nguyên tắc hoạt động của **ngăn xếp (stack)**.

b. Định nghĩa cấu trúc dữ liệu biểu diễn ngăn xếp chứa các số nguyên.

c. Viết giải thuật `push` thêm phần tử vào đỉnh của ngăn xếp.

d. Viết giải thuật `pop` để trả về giá trị và xoá phần tử ở đỉnh của ngăn xếp. Nếu ngăn xếp rỗng thì trả về giá trị `INT_MIN`.

e. Viết giải thuật `removeNegativeNodes` để xoá các nút có giá trị âm của ngăn xếp.

---

### Câu 3. (4,0 điểm)
Cho **cây tìm kiếm nhị phân** $T$, mỗi nút trong $T$ chứa một số nguyên được định nghĩa như sau:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};

Hãy thực hiện các nội dung sau:
a. Phát biểu định nghĩa của cây tìm kiếm nhị phân, cây nhị phân cân bằng.
b. Viết giải thuật countLeafNodes để đếm số nút lá của cây $T$.
c. Viết giải thuật findTreeHeight xác định chiều cao của cây $T$.
d. Viết giải thuật print3LargestNodes in ra 3 nút có giá trị lớn nhất của cây $T$.

---
**Gợi ý:**
Câu **3d (`print3LargestNodes`)** là một câu hỏi khá hay (in 3 nút lớn nhất của BST). Do tính chất của cây tìm kiếm nhị phân (Node phải > Node trái), 3 nút lớn nhất sẽ luôn nằm ở phía cực phải của cây.
* Bạn có muốn tôi viết code mẫu cho giải thuật này không?
* Hoặc bạn cần lời giải cho phần Stack (Câu 2)?
