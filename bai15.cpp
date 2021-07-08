#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;

int main() {
	freopen("bangnho.txt", "r", stdin);
    
	int d[MAX];
    int n, L;
    cin >> n;
	cin >> L;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    sort(d, d + n);

    int b1[MAX], b2[MAX]; //lưu băng của L1, L2
    int L1, L2;
    L1 = L2 = L;
    int h = 0; //chỉ số b1[]
    int k = 0; //chỉ số b2[]

    for (int i = 0; i < n; ++i) {
		if(L1 - d[i] >= 0) {
			b1[h] = d[i];
			h++;
			L1 -= d[i];
		}
		else if (L2 - d[i] >= 0) {
			b2[k] = d[i];
			k++;
			L2 -= d[i];
		}
		else break;
    }

	cout<<"L1:";
    for (int i = 0; i < h; ++i) {
        cout << b1[i] << ' ';
    }
    cout << "\nL2:";
    for (int i = 0; i < k; ++i) {
        cout << b2[i] << ' ';
    }

    cout << "\nTong so chuong trinh luu tru duoc la: " << h + k;
    return 0;
}