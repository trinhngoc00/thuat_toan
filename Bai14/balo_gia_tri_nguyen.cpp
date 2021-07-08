// Đọc file README.txt
#include <iostream>
using namespace std;

const int MAX = 100;

struct DoVat {
    int theTich;
    int giaTri;
};

void input(DoVat dovat[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> dovat[i].theTich;
        cin >> dovat[i].giaTri;
    }
}

void output(DoVat dovat[], int n, int soLuong[]) {
    for (int i = 0; i < n; ++i) {
        cout << '(' << dovat[i].theTich << ", " << dovat[i].giaTri << "): " << soLuong[i] << endl;
    }
}

// Sắp xếp giảm dần dựa theo tỷ lệ giaTri/theTich
void sapXep(DoVat dovat[], int n) {
    // Áp dụng Selection Sort
    for (int i = 0; i < n - 1; ++i) {
        int indexOfMin = i;
        for (int j = i + 1; j < n; ++j) {
            if (float(dovat[indexOfMin].giaTri) / dovat[indexOfMin].theTich < float(dovat[j].giaTri) / dovat[j].theTich) {
                indexOfMin = j;
            }
        }

        if (indexOfMin != i) {
            swap(dovat[indexOfMin], dovat[i]);
        }
    }
}

int greedy(DoVat dovat[], int n, int B, int soLuong[]) {
    sapXep(dovat, n);

    int tongGiaTri = 0;
    for (int i = 0; i < n; ++i) {
        soLuong[i] = B / dovat[i].theTich;
        B -= soLuong[i] * dovat[i].theTich;
        tongGiaTri += soLuong[i] * dovat[i].giaTri;
    }

    return tongGiaTri;
}

int main() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    DoVat dovat[MAX];
    int soLuong[MAX];  // Số lượng của từng món đồ
    int n;
    int B;  // Thể tích của balo là B
    cin >> n;
    cin >> B;

    input(dovat, n);
    int tongGiaTri = greedy(dovat, n, B, soLuong);
    output(dovat, n, soLuong);
    cout << "Tong gia tri max = " << tongGiaTri;

    return 0;
}