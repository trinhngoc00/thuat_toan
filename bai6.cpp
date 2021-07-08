#include <iostream>
using namespace std;

int main() {
	//int a[] = {10, 10, 8, 7, 7, 3, 2};
	//int a[] = {20, 19,7,18,17,15,15,14,13,12,19};
	//int a[] = {39,39,38,35,20,9};
	int a[] = {39, 38, 38, 38};
  int n = sizeof(a) / sizeof(a[0]);

	//sắp xếp giảm dần, trồng những cây có số ngày nhiều trước
	//VD: 20, 19, 19, 2
	//ngày để nở từng loại cây: 20+0, 19+1, 19+2, 2+3
	//lấy max của những ngày trên
	for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[i]) {
                swap(a[i], a[j]);
            }
        }
    }

	int max = 0;

	for(int i=0; i<n; i++) {
		cout<<a[i]<<"\t";
		int p = a[i] + i;
		if(p > max) max = p;
	}
	cout<<"\nSo ngay: "<<max;
	return 0;
}