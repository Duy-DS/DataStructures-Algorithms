#include <iostream>
#include <cmath>
#include <stack>

using namespace std;
bool isPrime(long num);

int main()
{
    // khai báo ngăn xếp
    stack <int> stack;
    long num; // số nhập vào từ bàn phím
    long temp; // biến tạm, bắt đầu từ num nhưng sẽ giảm theo hệ số (nguyên tố ) sau mỗi lần lặp
    long factor; // hệ số (nguyên tố) dùng để xác định thừa số trong mỗi lần lặp

    // nhập dữ liệu
    cout << "Nhập số nguyên lớn hơn 1: ";
    cin >> num;
    cout << endl;

    // xác thực dự liệu
    while (num <= 1)
    {
        cout << "Vui lòng nhập số nguyên lớn hơn 1: " << endl;
        cin >> num;
    }

    cout << "Thừa số nguyên tố của " << num << ": ";

    // nếu số nhập vào là số nguyên tố thì trả về chính nó
    if (isPrime(num))
    {
        cout << num << endl;
        return 0;
    }

    // nếu số nhập vào không phải là số nguyên tố
    temp = num;

    // số nguyên tố đầu tiên, số nguyên tố chẵn duy nhất
    factor = 2;

    while (temp > 1)
        // chia cho 2 tới khi không thể chia được nữa
        if (temp % 2 == 0)
        {
            stack.push(2); // thêm 2 vào ngăn xếp
            temp = temp / 2;
        }
        else
            break;
    // bắt đầu với số nguyên tố tiếp theo
    factor = 3;

    // tiếp tục xác định thừa số nguyên tố với điều kiện
    // nếu đổi thành factor <= sqrt(n) kết quả sẽ ra không chính xác
    // với một số trường hợp ví dụ như 14, 26, vv
    // hay sai với các trường hợp 2*x với x là 1 số nguyên tố
    while (temp > 1 && (factor <= num/2))
    {
        // nếu factor không phải là số nguyên tố thì tăng thêm 2 đơn vị
        if (!isPrime(factor))
            factor += 2;
        else if (temp % factor == 0) // nếu factor là số nguyên tố thì thực hiện việc chia lấy số dư
        {
            stack.push(factor); // nếu chia hết thì thêm factor vào đỉnh ngăn xếp
            temp = temp / factor; // biến tạm giảm theo hệ số factor
        }
        else // những trường hợp còn lại thì tăng factor lên 2 đơn vị
            factor += 2;
    }

    // in ra các phần tử của ngăn xếp
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }

    cout << endl;

    return 0;
}

// xác định một số có phải là số nguyên tố hay không
bool isPrime(long num)
{
    bool isPrimeNum; // khởi tạo cờ

    int sqrtNum;
    int divisor = 3;

    if (num == 2) // nếu là 2 thì kết luận là số nguyên tố
        isPrimeNum = true;
    else if (num % 2 == 0) // nếu chia hết cho 2 thì không phải là số nguyên tố
        isPrimeNum = false;
    else // trường hợp còn lại
    {
        isPrimeNum = true; // khởi tạo giá trị cho cờ

        sqrtNum = static_cast<int>(pow(static_cast<double>(num), 0.5)); // tính căn bậc 2 và lấy phần nguyên

        // thực hiện vòng lặp
        while (divisor <= sqrtNum)
        {
            if (num % divisor == 0) // nếu chia hết
            {
                isPrimeNum = false;
                break;
            }
            else
                divisor = divisor + 2; // tăng thương lên 2 đơn vị
        }
    }

    return isPrimeNum;
}