#include<iostream>
#include<string.h>
using namespace std;

int max(int a, int b) {
	if(a>b) return a;
	else return b;
}

void timxau(string x, string y, int n, int m) { //n,m: độ dài của x, y
	int L[n+1][m+1]; //ma trận L lưu bảng phương án, có thêm cột rỗng
	if(n == 0 || m == 0) {
		L[n+1][m+1] = 0;
	}
	else{
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= m; j++) {
				if(i == 0 || j == 0) {
					L[i][j] = 0;
				}
				else {
					if(x[i-1] != y[j-1])
						L[i][j] = max(L[i-1][j], L[i][j-1]);
					else 	L[i][j] =L[i-1][j-1] +1;
				}
			}
		}
	}

	//xuất bảng lưu phương án
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++) {
			cout<<L[i][j]<<"\t";
		}
		cout<<"\n";
	}

	cout<<"\nDo dai xau lon nhat: "<<L[n][m];

	//truy vết ngược tìm xâu con
	int i = n, j = m;
	string c=""; //lưu xâu con lớn nhất
	while(L[i][j] != 0) {
		if(x[i-1] == y[j-1]) {
			c = x[i-1] + c; 
			cout<<"\n"<<c;
			i--; j--;
		}
		else {
			if(L[i][j-1] > L[i-1][j])	j--;
			else i--;
		}
	}
	cout<<"\nXau con chung lon nhat:"<<c;
}

int main() {
	string x = "dabgf";
	string y = "abdfg";
	
	int n,m;
	n = x.length();
	m = y.length();
	
	timxau(x,y,n,m);

	return 0;
}