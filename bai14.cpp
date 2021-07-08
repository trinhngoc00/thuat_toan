#include<iostream>
using namespace std;

//balo giá trị nguyên
void tyso(int n, int a[], int p[], int B) {
	float t[n];

	//t = giá trị/thể tích. Tại sao?
	for(int i=0; i<n; i++) {
		t[i] = (float) p[i]/a[i]; 
	}

	//sắp xếp đồ vật theo giảm dần của t
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++) {
			if(t[i] < t[j]) {
				swap(t[i], t[j]);
				swap(a[i], a[j]);
				swap(p[i], p[j]);
			}
		}
	}
	cout<<"t[i]:";
	for(int i=0; i<n; i++) {
		cout<<t[i] <<"\t";
	}
	
	int sum=0; //thể tích đã chứa của balo
	int sodo[n]; //lưu số đồ lấy của vật thứ i
	int maxGiaTri = 0;
	
	int i=0;
	while(sum < B && i<n) {
		sodo[i] = (int) (B-sum)/a[i]; //lấy max SL của đồ a[i]
		if( (sum+a[i]*sodo[i]) <= B) {
			sum = sum + a[i]*sodo[i];
		}
		cout << "\nDo vat loai: (" << a[i] << ", " << p[i] << ")";
		cout << "\tSL:" << sodo[i];
		cout << "\tGia tri:" << p[i]*sodo[i];
		maxGiaTri += p[i]*sodo[i];
		i++;
	}
	cout<<"\nTong gia tri max: "<<maxGiaTri;
}

int main() {
	
	freopen("balo.txt", "r", stdin);
	int B, n;
	cin>>n;
	cin>>B;
	cout<<"B = "<<B<<endl;
	
	int a[n], p[n];
	for (int i = 0; i < n; i++) {
		cin>>a[i];
		cin>>p[i];
	}
	tyso(n,a,p, B);
	return 0;
}
