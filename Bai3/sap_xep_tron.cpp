// https://nguyenvanhieu.vn/thuat-toan-sap-xep-merge-sort/

#include <iostream>
using namespace std;

void print(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1];
    int R[n2];

    // Copy a sang 2 mảng L, R
    for (int i = 0; i < n1; ++i) {
        L[i] = a[left + i];
    }

    for (int j = 0; j < n2; ++j) {
        R[j] = a[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    // k = left chứ không phải k = 0
    // vì mảng con có thể bắt đầu từ bất cứ vị trí nào

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            a[k] = L[i];
            ++i;
        } else {
            a[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Mảng R đã hết, chỉ còn mảng L, dồn tất cả các phần tử còn lại của L vào a
    while (i < n1) {
        a[k] = L[i];
        ++i;
        ++k;
    }

    // Hoặc mảng L đã hết, chỉ còn mảng R, dồn tất cả các phần tử còn lại của R
    // vào a
    while (j < n2) {
        a[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(int a[], int left, int right) {
    // Chỉ sort mảng có từ 2 phần tử trở lên
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

int main() {
    int a[] = {3, 2, 1, 4, 8, 0};
    int n = sizeof(a) / sizeof(a[0]);

    mergeSort(a, 0, n - 1);

    print(a, n);
    return 0;
}