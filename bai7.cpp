#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 10000;

// => Dãy công việc lớn nhất mà không có công việc nào chồng nhau là 3, 5, 1 (dãy công việc có tổng số công việc là 3)
// => Để tìm được dãy này trước tiên ta cần sắp xếp dãy công việc theo
//    chiều tăng dần của thời gian kết thúc:
//    1 3
//    2 4
//    1 6
//    3 7
//    7 9

// * Ta bắt đầu với công việc đầu tiên (1 3) thời gian kết thúc cv tại 3
// => Chọn tiếp được công việc (3 7) vì thời gian bắt đầu của công việc này là tại 3 (3 >= thời gian kết thúc cv phía trước)
//    thời gian kết thúc cv tiếp theo này tại 7
// => Chọn tiếp được công việc (7 9) vì thời gian bắt đầu của công việc này là tại 7 (7 >= thời gian kết thúc cv phía trước)
//    thời gian kết thúc cv tại 9
// => Đã duyệt hết khả năng với công việc bắt đầu là (1, 3) => dãy có 3 công việc

// * Tiếp theo ta lặp lại với dãy công việc bắt đầu tại (2 4)
// => Tương tự ta có dãy công việc (2 4) (7 9) => dãy có 2 công việc (nhỏ hơn dãy phía trên với 3 công việc) => loại

// * Lặp lại đến hết

// => Vậy dãy công việc lớn nhất là (1 3) (3 7) (7 9) với 3 công việc

// test case
// 5
// 7 9
// 2 4
// 1 3
// 1 6
// 3 7

struct CongViec {
	CongViec() {}

    CongViec(int s, int f) {
        this->s = s;
        this->f = f;
    }

    int s; //start
    int f;	//finish
};

bool compare(CongViec a, CongViec b) {
    return a.f < b.f;
}

CongViec cv[MAX];
int n;

vector<CongViec> result; //vecto trả về ds cv kết quả

int main() {
	freopen("congviec.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
		cin >> cv[i].s >> cv[i].f;
    }

    sort(cv, cv + n, compare); //trả về sắp xếp tăng dần của thời gian kết thúc

    int demMax = 0; // đếm số cv lớn nhất

    for (int i = 0; i < n; ++i) {
        int batdau = cv[i].s;
        int ketthuc = cv[i].f;
        int dem = 1;

		vector<CongViec> temp; 
		temp.push_back(CongViec(batdau, ketthuc)); //thêm cv vào temp

        for (int j = i + 1; j < n; ++j) { //kiểm tra các cv tiếp theo
            if (cv[j].s >= ketthuc) { //cv tiếp theo có start >= ketthuc của cv trước đó, thì thoả mãn
                batdau = cv[j].s;
                ketthuc = cv[j].f;
                dem++;

				temp.push_back(CongViec(batdau, ketthuc));
            }
        }

        if (dem > demMax) { //sl cv của dãy cv hiện tại > max, lấy dãy cv này
            demMax = dem;
			result = temp;
        }
    }
    cout << "So cong viec cua day lon nhat:" << demMax;
	cout << "\nDanh sach cong viec:\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << result.at(i).s << ' ' << result.at(i).f << endl;
    }
    return 0;
}