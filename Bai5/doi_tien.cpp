// Bài này giải theo phương pháp tham lam
// Xem bài 14 trước

#include <iostream>
using namespace std;

const int MAX = 100;

// file in.txt được tổ chức dưới dạng
// Dòng 1: Số lượng mệnh giá
// Dòng 2: Các mệnh giá tương ứng
// Dòng 3: W - Số tiền cần đổi

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    int tien[MAX];
    for (int i = 0; i < n; ++i) {
        cin >> tien[i];
    }

    // Sắp xếp tiền theo mệnh giá giảm dần
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (tien[j] > tien[i]) {
                swap(tien[i], tien[j]);
            }
        }
    }

    int W;
    cin >> W;

    // Số lượng từng mệnh giá được lưu ở mảng soLuong
    int soLuong[MAX];

    // Đổi tiền
    for (int i = 0; i < n; ++i) {
        soLuong[i] = W / tien[i];
        W -= soLuong[i] * tien[i];
    }

    // Kiểm tra xem có thể đổi được hay không:
    if (W == 0) {
        for (int i = 0; i < n; ++i) {
            cout << tien[i] << "K: " << soLuong[i] << " to" << endl;
        }
    } else {
        cout << "Khong the doi duoc tien";
    }

    return 0;
}