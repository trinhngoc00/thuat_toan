// Xây dựng chương trình liệt kê các dãy nhị phân có n phần tử
// https://youtu.be/__dGkdmXiKU

#include <iostream>
using namespace std;

const int MAX = 100;

void show(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << endl;
}

void Try(int i, int a[], int n) {
    for (int j = 0; j <= 1; ++j) {
        a[i] = j;
        if (i == n - 1) {
            show(a, n);
        } else {
            Try(i + 1, a, n);
        }
    }
}

int main() {
    int a[MAX];
    int n = 2;

    Try(0, a, n);

    return 0;
}