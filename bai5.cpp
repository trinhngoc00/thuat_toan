#include <iostream>
using namespace std;

const int MAX = 100;

// Bài này giải theo phương pháp tham lam
// Xem bài 14 trước

// file in.txt được tổ chức dưới dạng
// Dòng 1: Số lượng mệnh giá
// Dòng 2: Các mệnh giá tương ứng
// Dòng 3: M - Số tiền cần đổi

int main() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    int tien[MAX];	//mệnh giá tiền
    for (int i = 0; i < n; ++i) {
        cin >> tien[i];
    }

    // Sắp xếp tiền theo mệnh giá giảm dần
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (tien[j] > tien[i]) {
                swap(tien[i], tien[j]);
            }
        }
    }

    int M;
    cin >> M; //nhập số tiền cần đổi

	int sum = 0;	//lưu số tiền đã lấy được

	int soto[MAX] = {0};	// Số lượng từng mệnh giá
	
	int i = 0;
	while(sum != M && i<n) {
		soto[i] = (M - sum)/tien[i];
		if( (sum + tien[i]*soto[i]) <= M ){
			sum = sum + tien[i]*soto[i];
		}
		i++;
	}

	// Kiểm tra xem có thể đổi được hay không:
	if(sum == M) 
		for (int i = 0; i < n; ++i) {
            cout <<"\n"<< tien[i] << "K: " << soto[i] << " to";
        }
	else cout<<"\nKhong doi duoc";

    return 0;
}