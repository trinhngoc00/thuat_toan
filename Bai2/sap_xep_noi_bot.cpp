// https://youtu.be/IWT-Uoz_Sb8

#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main() {
    int a[] = {3, 2, 10, 5, 8, 4, 7};
    int n = sizeof(a) / sizeof(a[0]);

    bubbleSort(a, n);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    return 0;
}