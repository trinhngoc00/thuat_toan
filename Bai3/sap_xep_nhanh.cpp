#include <iostream>
using namespace std;

void quickSort(int a[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    // Phải dùng <= ở while và if:
    // Vì ở if bên dưới sẽ ++i, --j
    // nên khi đệ quy quickSort sẽ không có sort mảng chứa pivot nữa
    // VD: Mảng: 2 4 3 1 5 (pivot = 3)
    // Sau vòng while ta được mảng: 2 1 3 4 5
    // Ta sẽ chỉ gọi đệ quy cho 2 mảng con là: 2 1 và 4 5
    while (i <= j) {
        while (a[i] < pivot) {
            ++i;
        }

        while (a[j] > pivot) {
            --j;
        }

        if (i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
        // Sẽ có 1 thời điểm swap(pivot, pivot)
        // Nhưng nó không hề thừa thãi
        // điều đó giúp ++i, --j như đã giải thích ở trên
    }

    if (left < j) quickSort(a, left, j);
    if (right > i) quickSort(a, i, right);
}

void print(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}

int main() {
    int a[] = {3, 2, 1, 4, 8, 0};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);

    print(a, n);
    return 0;
}