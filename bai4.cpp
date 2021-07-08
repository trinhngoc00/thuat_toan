#include <iostream>
using namespace std;

// tính a mũ n bằng chia để trị
// Chia để trị: chia bài toán lớn thành các bài toán con, kết quả của bài toán lớn sẽ phụ thuộc vào kết quả của các bài toán con

int muDuong(int a, int n) {
    if (n == 0) return 1; // a^0 = 1

		//chia đôi luỹ thừa, VD: 3^6 = 3^3 * 3^3
    if (n % 2 == 0) 
        return muDuong(a, n / 2) * muDuong(a, n / 2);
    else
        // VD: n = 5 lẻ => return a^2 * a^2 * a
        return muDuong(a, (n - 1) / 2) * muDuong(a, (n - 1) / 2) * a;
}

double mu(int a, int n) {
    if (n >= 0)
        return muDuong(a, n);
		//nếu 2^-3 = 1/(2^3)
    return 1.0 / muDuong(a, abs(n));
}

int main() {
    int a = 2, n = 10;

    cout << a << "^" << n << " = " << mu(a, n);
    return 0;
}