// https://youtu.be/IWT-Uoz_Sb8

#include <iostream>
using namespace std;

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int position = i;
        int current = a[i];

        while (position > 0 && current < a[position - 1]) {
            a[position] = a[position - 1];
            --position;
        }

        a[position] = current;
    }
}

int main() {
    int a[] = {3, 2, 10, 5, 8, 4, 7};
    int n = sizeof(a) / sizeof(a[0]);

    insertionSort(a, n);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }

    return 0;
}