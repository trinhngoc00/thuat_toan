// Cho 2 số tự nhiên N và K. Hãy đưa ra các tổ hợp chập K của 1, 2,.., N
// https://www.youtube.com/watch?v=RlqaVmgUeac

#include <iostream>
using namespace std;

const int MAX = 100;

void show(int a[], int k) {
    for (int i = 1; i <= k; ++i) {
        cout << a[i];
    }
    cout << endl;
}

// Tại sao lại start ở j = a[i - 1]?
// Tại sao: j <= n - k + i ?
// Xem video trên sẽ rõ

void Try(int i, int a[], int n, int k) {
    for (int j = a[i - 1] + 1; j <= n - k + i; ++j) {
        a[i] = j;
        if (i == k) {
            show(a, k);
        } else {
            Try(i + 1, a, n, k);
        }
    }
}

int main() {
    int a[MAX] = {0};
    int n = 5, k = 3;

    Try(1, a, n, k);
}