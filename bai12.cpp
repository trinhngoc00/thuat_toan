#include <iostream>
using namespace std;

const int MAX = 100;

//liệt kê các tổ hợp của n phần tử
// Cho 2 số tự nhiên N và K. Hãy đưa ra các tổ hợp chập K của N
// https://www.youtube.com/watch?v=RlqaVmgUeac

void show(int a[], int k) {
    for (int i = 1; i <= k; ++i) {
        cout << a[i];
    }
    cout << endl;
}

// Tại sao lại start ở j = a[i - 1]?
// Tại sao: j <= n - k + i ?
// VD: k=3,n=5 có các khả năng 123,124,125,134, 135, 145, 234, 235, 245, 345
// phần tử thứ 1 luôn trong khoảng từ 1-3
// phần tử thứ 2 luôn trong khoảng từ 2-4
// phần tử thứ 3 luôn trong khoảng từ 3-5

void Try(int i, int a[], int n, int k) {
    for (int j = a[i - 1] + 1; j <= n - k + i; ++j) { //j: gía trị chấp nhận cho phần tử của a
        a[i] = j;
		//cout<<"a["<<i<<"]="<<j<<endl;
        if (i == k) {
            show(a, k);
        } else {
            Try(i + 1, a, n, k);
        }
    }
}

int main() {
    int a[MAX] = {0};
    int n = 4, k = 3;
	for(int i = 1; i <= n; i++) {
		Try(1, a, n, i); //tổ hợp chập i của n phần tử mảng a
	}
	return 0;
}