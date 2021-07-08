// https://youtu.be/zMYhIsLoPL0
// Trong video có minh họa cách tạo bảng phương án

#include <iostream>
using namespace std;

const int MAX = 2001;

int a[MAX][MAX];

void solve(string s1, string s2) {
    int n = s1.length();  // n Cot
    int m = s2.length();  // m Hang

    // Khởi tạo cột 0 và hàng 0 với giá trị bằng 0
    // Do mảng a khai báo là biến global nên mặc định tất cả
    // các giá trị bằng 0 nên ta có thể bỏ qua bước này.

    // Tạo bảng phương án:
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[j - 1] == s2[i - 1]) {
                a[i][j] = a[i - 1][j - 1] + 1;
            } else {
                a[i][j] = max(a[i][j - 1], a[i - 1][j]);
            }
        }
    }

    // In ra độ dài của xâu con chung
    cout << "Do dai xau con chung: " << a[m][n] << endl;

    // Tìm xâu con chung từ bảng phương án
    int i = m;
    int j = n;
    string result;
    while (a[i][j] != 0) {
        if (s1[j - 1] == s2[i - 1]) {
            result = s1[j - 1] + result;
            --i;
            --j;
        } else if (a[i][j - 1] > a[i - 1][j]) {
            --j;
        } else {
            --i;
        }
    }

    cout << result;
}

int main() {
    string s1 = "abc1def2ghi3";
    string s2 = "abcdefghi123";

    // string s1, s2;
    // cin >> s1 >> s2;

    solve(s1, s2);

    return 0;
}