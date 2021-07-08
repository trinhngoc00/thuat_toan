// https://youtu.be/ohHWQf1HDfU?t=436
// Trầm kảm mất thôi...

#include <iostream>
using namespace std;

// Cách này chỉ xuất ra độ dài xâu con có tổng lớn nhất
// nhưng làm sao để xuất ra xâu đó thì chưa làm đc

int dayConMax(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }

    int m = n / 2;
    int left_MSS = dayConMax(arr, m);
    int right_MSS = dayConMax(arr + m, n - m);
    int leftsum = INT_MIN, rightsum = INT_MIN, sum = 0;

    for (int i = m; i < n; i++) {
        sum += arr[i];
        rightsum = max(rightsum, sum);
    }

    sum = 0;
    for (int i = (m - 1); i >= 0; i--) {
        sum += arr[i];
        leftsum = max(leftsum, sum);
    }
    int ans = max(left_MSS, right_MSS);
    return max(ans, leftsum + rightsum);
}

int main() {
    int arr[] = {-2, 11, -4, 13, -5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Do dai xau con co tong lon nhat:"<< dayConMax(arr, n) << "\n";

    return 0;
}