// https://youtu.be/ZpVjwr7RB7Q

#include <iostream>
using namespace std;

const int MAX = 100;

void show(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << endl;
}

void Try(int i, int a[], int checked[], int n) {
    for (int j = 1; j <= n; ++j) {
        if (checked[j] == false) {	//chưa được chọn, chấp nhận giá trị j
            a[i] = j;
			cout<<"\na["<<i<<"]="<<j;
            checked[j] = true; //đã được chọn

            if (i == n - 1) { //đến phần tử cuối của hoán vị, in ra
                show(a, n);
            } else { 
                Try(i + 1, a, checked, n); //phần tử tiếp theo của hoán vị
            }

            checked[j] = false; //tái tạo trở lại ban đầu
        }
    }
}

int main() {
    int a[MAX]; //lưu từng phần tử của hoán vị mới
    int checked[MAX] = {false};

    int n = 3;
    Try(0, a, checked, n);

    return 0;
}