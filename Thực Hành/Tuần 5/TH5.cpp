#include <iostream>
using namespace std;

// khai báo hằng số
const int SIZE = 1000;

// định nghĩa hàm
void printListInfo(int list[]);
void fill(int list[], int length);
void selectionSort(int list[], int length);
int binarySearch(const int list[], int length,int& comparisons, const int& searchItem);
int binSeqSearch15(const int list[], int length,int& comparisons, const int& searchItem);
int seqSearch2(const int list[], int first, int last,int& comparisons, const int& searchItem);
int minLocation(int list[], int first, int last);
void swap(int list[], int first, int second);

int main()
{
    int intList[SIZE];
    int num;
    int loc;
    int comparisons;
    fill(intList, SIZE);

    selectionSort(intList, SIZE);

    cout << "Mảng sau khi đã sắp xếp: " << endl;
    printListInfo(intList);

    cout << "Nhập vào phần tử cần tìm: ";
    cin  >>  num;
    cout << endl;

    cout << "*****Sử dụng tìm kiếm nhị phân*****" << endl;

    comparisons = 0;
    // Khởi tạo biến đếm so sánh
    loc = binarySearch(intList, SIZE, comparisons, num);

    if (loc != -1)
        // Nếu hàm binarySearch trả về -1 thì xuất ra thông báo không tìm được phần tử
        cout << "Phần tử được tìm thấy tại vị trí " << loc
             << ";  Số lần thực thiện so sánh = "
             << comparisons << endl;
    else
        // Ngược lại xuất ra thông báo tìm được phần tử và xuất ra số lần thực hiện so sánh
        cout << "Phần tử không có trong mảng. "
             << " Số lần thực hiện so sánh = "
             << comparisons << endl;

    cout << "*****Sử dụng tìm kiếm nhị phân và tuần tự*****" << endl;

    comparisons = 0;
    // Khởi tạo biến đếm so sánh
    loc = binSeqSearch15(intList, SIZE, comparisons, num);

    if (loc != -1)
        // Nếu hàm binSeqSearch15 trả về -1 thì xuất ra thông báo không tìm được phần tử
        cout << num << "  được tìm thấy tại vị trí " << loc
             << ";  Số lần thực hiện so sánh = "
             << comparisons << endl;
    else
        // Ngược lại xuất ra thông báo tìm được phần tử và xuất ra số lần thực hiện so sánh
        cout << num << " không có trong mảng  "
             << " Số lần thực hiện so sánh = "
             << comparisons << endl;


    return 0;
}

// hàm in các phần tử trong mảng
void printListInfo(int list[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << list[i] << " ";
        if (i % 15 == 0)
            cout << endl;
    }

    cout << endl;
}

// hàm khởi tạo giá trị ngẫu nhiên cho mảng
void fill(int list[], int length)
{
    srand(time(0));

    for (int i = 0; i < length; i++)
        list[i] = rand() % 20000;
    /* Thay đổi 20000 để thay đổi khoảng xác định
     của các giá trị ngẫu nhiên, giá trị càng lớn
     khoảng cách giữa các giá trị ngẫu nhiên càng lớn,
     giá trị càng nhỏ hơn so với length thì các giá trị
     ngẫu nhiên sẽ giống nhau*/
}

// tìm kiếm nhị phân
int binarySearch(const int list[], int length,int& comparisons, const int& searchItem)
{
    int first = 0;          // khởi tạo vị trí đầu tiên
    int last = length - 1;  // khởi tạo vị trí cuối cùng
    int mid = -1;           // khởi tạo vị trí mid 

    bool found = false;     // tạo cờ để xác định quá trình tìm kiếm phần tử

    // Khi vẫn còn phần tử trong mảng và chưa tìm được phần tử cần tìm 
    while (first <= last && !found)
    {
        mid = (first + last) / 2;   // Lấy vị trí ở giữa mảng

        comparisons++;              // Tăng biến đếm so sánh lên
        if (list[mid] == searchItem)// Nếu list[mid] = phần tử muốn tìm kiếm cho found=true
            found = true;
        else                        // Ngược lại
        {
            comparisons++;          // Tăng biến đếm so sánh lên
            if (list[mid] > searchItem) // Nếu list[mid] > phần tử muốn tìm, ta tìm nửa trái của mảng 
                last = mid - 1;
            else                    // Ngược lại tìm nửa phải của mảng
                first = mid + 1;
        }
    }

    if (found)                      // Nếu found=true trả về vị trí mid
        return mid;
    else
        return -1;
}

// Hàm tìm kiếm tuần tự nếu phần tử trong mảng <15 
// thì sẽ chuyển qua tìm kiếm tuần tự
int binSeqSearch15(const int list[], int length,
                   int& comparisons, const int& searchItem)
{
    int first = 0;
    int last = length - 1;
    int mid = -1;

    bool found = false;

    // Khi phần tử trong mảng còn lớn hơn 15 
    // và chưa tìm thấy phần tử muốn tìm
    while (last - first > 15 && !found)
    {
        mid = (first + last) / 2;       // Lấy vị trí ở giữa mảng

        comparisons++;                  // Tăng biến đếm so sánh lên

        if (list[mid] == searchItem)    // Nếu list[mid] = phần tử muốn tìm kiếm cho found=true
            found = true;
        else
        {
            comparisons++;              // Tăng biến đếm so sánh lên

            if (list[mid] > searchItem) // Nếu list[mid] > phần tử muốn tìm, ta tìm nửa trái của mảng 
                last = mid - 1;
            else                        // Ngược lại tìm nửa phải của mảng
                first = mid + 1;
        }
    }

    if (found)  // Nếu found=true trả về vị trí mid
        return mid;
    else        // Nếu phần tử trong mảng nhỏ hơn 15 phần tử ta thực hiện tìm kiếm tuần tự
        return seqSearch2(list, first, last, comparisons, searchItem);
}

// hàm tìm kiếm tuần tự
int seqSearch2(const int list[], int first, int last,int& comparisons, const int& searchItem)
{
    int loc;
    bool found = false;

    loc = first;            // cho loc = vị trí đầu tiên

    // chạy tuần tự từ đầu đến cuối mảng
    while (loc <= last && !found)
    {
        if (list[loc] == searchItem)    // nếu list[loc] = phần tử cần tìm cho found = true
            found = true;
        else
            loc++;

        comparisons++;                  // tăng biến đếm số lần so sánh
    }

    if (found)
        return loc;
    else
        return -1;
}

// sắp xếp chèn
void selectionSort(int list[], int length)
{
    int loc, minIndex;

    // duyệt từng phần tử của mảng
    for (loc = 0; loc < length; loc++)
    {
        // tìm phần tử nhỏ nhất trong mảng
        minIndex = minLocation(list, loc, length - 1);
        // đổi chỗ phần tử tại loc với phần tử nhỏ nhất trong mảng
        swap(list, loc, minIndex);
    }
}

// hàm đổi chỗ 2 phần tử
void swap(int list[], int first, int second)
{
    int temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

// hàm tìm phần tử nhỏ nhất trong mảng
int minLocation(int list[], int first, int last)
{
    int loc, minIndex;

    // mặc định phần tử nhỏ nhất trong mảng là phần tử đầu
    minIndex = first;

    // duyệt từng phần tử của mảng
    for (loc = first + 1; loc <= last; loc++)
        // nếu phần tử nào trong mảng nhỏ hơn phần tử đầu tiên thì cập nhật lại        
        if (list[loc] < list[minIndex])
            minIndex = loc;

    return minIndex;
} 