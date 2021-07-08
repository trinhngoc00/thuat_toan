#include <iostream>
using namespace std;

//sap xep tang dan
void sapXepNoiBot(int s[], int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < n-i-1; j++) {
			if(s[j] > s[j+1]) swap(s[j], s[j+1]);
		}
	}
}

// Chọn là chọn phần tử nhỏ nhất đưa về đầu
// Cách sắp xếp này tương tự như cách sắp xếp 2 vòng for đơn giản
// mà trước đây hay dùng nhưng được cải tiến hơn là chỉ swap a[i] với min thôi
// còn kiểu cũ thì cứ a[j] < a[i] là swap luôn
void sapXepChon(int s[], int n) {
	for (int i = 0; i < n - 1; ++i) {
        int indexOfMin = i;
        for (int j = i + 1; j < n; ++j) {
            if (s[j] < s[indexOfMin]) {
                indexOfMin = j;
            }
        }

        if (indexOfMin != i) {
            swap(s[i], s[indexOfMin]);
        }
    }
}
void sapXepChen(int s[], int n) { 	// https://youtu.be/IWT-Uoz_Sb8
	for (int i = 1; i < n; ++i) {
        int position = i;
        int current = s[i];

        while (position > 0 && current < s[position - 1]) {
            s[position] = s[position - 1];
            --position;
        }

        s[position] = current;
    }
}
int main() {
	int s[] = {3, 2, 10, 5, 8, 4, 7};
  	int n = sizeof(s) / sizeof(s[0]);

	sapXepNoiBot(s, n);
	//sapXepChon(s,n);
	//sapXepChen(s,n);

	cout<<"\nSap xep tang dan:";
	for (int i = 0; i < n; ++i) {
    	cout << s[i] << "\t";
  	}	

	return 0;
}