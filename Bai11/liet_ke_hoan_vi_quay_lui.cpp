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
        if (checked[j] == false) {
            a[i] = j;
            checked[j] = true;

            if (i == n - 1) {
                show(a, n);
            } else {
                Try(i + 1, a, checked, n);
            }

            checked[j] = false;
        }
    }
}

int main() {
    int a[MAX];
    int checked[MAX] = {false};

    int n = 4;
    Try(0, a, checked, n);

    return 0;
}