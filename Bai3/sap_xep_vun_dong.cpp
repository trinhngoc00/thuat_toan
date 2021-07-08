// http://www.hoclaptrinh.xyz/2014/06/code-cc-thuat-toan-sap-xep-vun-ong-heap.html#

// CTDL Heap là gì? là một trường hợp đặc biệt của cấu trúc dữ liệu cây nhị phân
// cân bằng

// Max-Heap: ở đây giá trị của nút gốc là lớn hơn hoặc bằng giá trị của
// các nút con.

#include <iostream>
using namespace std;

void print(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
void pushDown(int a[], int i, int n) {
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // left < n: để đảm bảo con trái không vượt quá mảng
    if (left < n && a[left] > a[root]) {
        root = left;
    }

    // right < n: để đảm bảo con phải không vượt quá mảng
    if (right < n && a[right] > a[root]) {
        root = right;
    }

    // Sau 2 lệnh if thì index của root sẽ là index của con lớn nhất

    if (root != i) {
        swap(a[i], a[root]);

        // Đệ quy tiếp tục với cây con
        pushDown(a, root, n);
    }
}

// Sap xep tang dan
void heapSort(int a[], int n) {
    // Bước 1: Xây dựng Max-Heap
    // Vòng lặp chạy từ i = n / 2 - 1 đến 0
    // VD: n = 5 => i = 1, 0
    // Tại sao lại lặp có 2 lần?
    // Vì 1 cây nhị phân chỉ có n / 2 gốc mà thôi
    // mà index của mảng start từ 0 -> for n/2-1 tới 0
    // Vậy tạo sao lại chạy từ i = n/2-1 về 0 mà không phải từ 0 đến n/2-1
    // Vì ta cần phải tạo max-heap từ cây con ở phía dưới trước,
    // xong cây con ở phía dưới rồi mới đến gốc của cây con đó
    for (int i = n / 2 - 1; i >= 0; --i) {
        pushDown(a, i, n);
    }

    // Bước 2: Đưa phần tử lớn nhất về cuối mảng và loại nó ra khỏi heap
    // và lặp lại đến khi mảng được sắp xêp
    for (int i = n - 1; i > 0; --i) {
        // Đổi chỗ phần tử đầu(phần tử lớn nhất) với phần tử cuối mảng
        swap(a[0], a[i]);

        // Phần tử cuối đã là lớn nhất, ta không cần xét nữa
        // Tạo lại max-heap (không chứa phần tử cuối)
        // pushDown lại bắt đầu từ 0 (gốc) mà không phải dùng for từ cây con như
        // trên vì các cây con vẫn là max-heap chỉ có gốc bị đổi nên chỉ cần
        // pushDown từ gốc là được
        pushDown(a, 0, i);

        // dùng i > 0 mà không phải i >= 0 vì khi i == 0 thì lúc đó cây chỉ còn
        // 1 phần tử nên không cần phải đổi chỗ làm gì cả => dùng i > 0
    }
}

int main() {
    int a[] = {2, 3, 1, 9, 4};
    int n = sizeof(a) / sizeof(a[0]);

    heapSort(a, n);

    print(a, n);
    return 0;
}