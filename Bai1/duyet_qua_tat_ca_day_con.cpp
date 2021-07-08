#include <iostream>
using namespace std;

const int MAX = 100;

int main() {
    int s[] = {-2, 11, -4, 13, -5, 2};
    int n = sizeof(s) / sizeof(s[0]);
		
    int tongMax = INT_MIN;
    int start = 0;
    int end = 0;

    for (int i = 0; i < n; ++i) {
        int tong = s[i];
        for (int j = i + 1; j < n; ++j) {
            tong += s[j];

            if (tong > tongMax) {
                tongMax = tong;
                start = i;
                end = j;
            }
        }
    }

    cout << "Day con co tong lon nhat bang " << tongMax << " la: ";
    for (int i = start; i <= end; ++i) {
        cout << s[i] << "; ";
    }

    return 0;
}