#include <iostream>
using namespace std;

const int MAX = 100;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int start, end;
    cin >> start >> end;

    int matrix[MAX][MAX];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == -1) {
                matrix[i][j] = 999;
            }
        }
    }

    int a[MAX];
    int b[MAX] = {0};
    int p[MAX];

    // Khởi tạo
    for (int i = 1; i <= n; ++i) {
        a[i] = matrix[start][i];
        p[i] = start;
    }
    b[start] = 1;

    // Xây dựng
    int k = start;
    while (k != end) {
        for (int i = 1; i <= n; ++i) {
            cout << p[i] << ' ';
        }
        cout << endl;

        int min = 999;
        int minIndex = -1;

        for (int i = 1; i <= n; ++i) {
            if (b[i] == 0 && a[i] < min) {
                min = a[i];
                minIndex = i;
            }
        }

        k = minIndex;
        b[k] = 1;

        for (int i = 1; i <= n; ++i) {
            if (b[i] == 0 && matrix[k][i] + a[k] < a[i]) {
                a[i] = matrix[k][i] + a[k];
                p[i] = k;
            }
        }
    }

    cout << "Do dai vet: " << a[k] << endl;
    // Truy vết
    int vitri = end;
    while (vitri != start) {
        cout << vitri << " -> ";
        vitri = p[vitri];
    }
    cout << start;

    return 0;
}