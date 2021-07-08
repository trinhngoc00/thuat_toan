#include <iostream>
using namespace std;
const int MAX = 100;

//tìm dãy con có tổng lớn nhất

/* Bảng phương án có dạng như sau
-2  9  5  18  13  15
 0  11 7  20  15  17
 0  0 -4  9   4   6
 0  0  0  13  8   10
 0  0  0  0  -5  -3
 0  0  0  0   0   2
*/
void quyHoachDong(int s[], int n) {
	int a[MAX][MAX] = {0};

	// Lập bảng phương án
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				a[i][j] = s[i];
			}
			else if (j > i) {
				a[i][j] = a[i][j - 1] + s[j];
			}
			cout << a[i][j] << "\t\t";
		}
		cout << "\n";
	}

	int tongMax = INT_MIN;
	int start = 0;
	int end = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j >= i && a[i][j] > tongMax) {
				tongMax = a[i][j];
				start = i;
				end = j;
			}
		}
	}

	cout << "\nDay con co tong lon nhat bang " << tongMax << " la: \n";
	for (int i = start; i <= end; ++i) {
		cout << s[i] << "; ";
	}
}

void duyetTatCa(int s[], int n) {
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

	cout << "\nDay con co tong lon nhat bang " << tongMax << " la: \n";
	for (int i = start; i <= end; ++i) {
		cout << s[i] << "; ";
	}
}

int chiaDeTri(int s[], int n) {
	if (n == 1) {
        return s[0];
    }

    int m = n / 2;
    int left_MSS = chiaDeTri(s, m);
    int right_MSS = chiaDeTri(s + m, n - m);
    int leftsum = INT_MIN, rightsum = INT_MIN, sum = 0;

    for (int i = m; i < n; i++) {
        sum += s[i];
        rightsum = max(rightsum, sum);
    }

    sum = 0;
    for (int i = (m - 1); i >= 0; i--) {
        sum += s[i];
        leftsum = max(leftsum, sum);
    }
    int ans = max(left_MSS, right_MSS); //max mảng trái và phải
    return max(ans, leftsum + rightsum); 
}


int main() {
	int s[] = {-2, 11, -4, 13, -5, 2};
	int n = sizeof(s) / sizeof(s[0]);

	//quyHoachDong(s, n);
	//duyetTatCa(s,n);
	cout << "\nDay con co tong lon nhat bang " << chiaDeTri(s,n) << " la: \n";
	return 0;
}