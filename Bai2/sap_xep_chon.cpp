// Chọn là chọn phần tử nhỏ nhất đưa về đầu

// Cách sắp xếp này tương tự như cách sắp xếp 2 vòng for đơn giản
// mà trước đây hay dùng nhưng được cải tiến hơn là chỉ swap a[i] với min thôi
// còn kiểu cũ thì cứ a[j] < a[i] là swap luôn

#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int indexOfMin = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[indexOfMin]) {
                indexOfMin = j;
            }
        }

        if (indexOfMin != i) {
            swap(a[i], a[indexOfMin]);
        }
    }
}

int main() {
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    selectionSort(a, n);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }

    return 0;
}