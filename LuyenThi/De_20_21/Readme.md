# ĐỀ THI KẾT THÚC HỌC PHẦN
**TRƯỜNG ĐẠI HỌC SÀI GÒN** **Học phần:** Cấu trúc Dữ liệu và Giải thuật  
**Mã học phần:** 841108  
**Năm học:** 2020 – 2021  
**Thời gian làm bài:** 90 phút (không kể thời gian phát đề)  
**Đề thi số:** 1  

> **Lưu ý:** Sinh viên KHÔNG được sử dụng tài liệu.

---

### Câu 1 (4,0 điểm)
Cho một dãy số $n$ nguyên $a[0], a[1], \dots, a[n-1]$.

1.  Cho biết ý tưởng của giải thuật sắp xếp bằng phương pháp sắp xếp nhanh (Quick Sort). (1.5 điểm)
2.  Hãy minh họa quá trình sắp tăng dần cho dãy số `7, 9, 10, 6, 15, 16, 12` theo giải thuật sắp xếp nhanh (Quick Sort). (1 điểm)
3.  Giả sử dãy số nguyên $n$ số trên đã được sắp xếp, viết hàm tìm kiếm nhị phân kiểm tra một giá trị nguyên $x$ có nằm trong dãy số hay không? Nếu $x$ có trong dãy số trả về vị trí của $x$, ngược lại không có trong dãy số trả về -1. (1.5 điểm)

---

### Câu 2 (3,0 điểm)
Cho một danh sách liên kết đơn mỗi nút chứa một số nguyên với NODE như sau:

```cpp
struct NODE {
    int data;
    NODE *next;
};
```
1. Viết hàm thêm một nút có giá trị nguyên $x$ vào vị trí thứ $i$ trong danh sách biết $0 \le i \le n$. (1 điểm)
2. Viết hàm tìm và trả về vị trí của một nút có giá trị số nguyên $x$ trong danh sách liên kết. Nếu $x$ có trong danh sách trả về vị trí của $x$, ngược lại không có trong danh sách trả về -1. (1 điểm)
3. Viết hàm tính và trả về giá trị trung bình cộng các giá trị nguyên có trong danh sách liên kết. (1 điểm)
---
### Câu 3 (3,0 điểm)
Cho một cây nhị phân tìm kiếm (Binary Search Tree) giá trị tại mỗi nút (node) là số nguyên với NodeTree như sau:
```cpp
struct NodeTree {
    int data;
    Node* left;
    Node* right;
};
```
.
      <img width="241" height="222" alt="image" src="https://github.com/user-attachments/assets/54ca084b-4a39-425b-b625-1de8e35c9c66" />

Hãy viết dãy số trên của cây trên với phép duyệt NRL (Node-Right-Left). (1 điểm)

Viết hàm thêm một nút vào cây nhị phân tìm kiếm. (1 điểm)

Hãy viết hàm đếm số nút lá trên cây. (1 điểm)
