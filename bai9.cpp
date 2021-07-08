#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
//biến đổi xâu X thành Y, tìm số thao tác ít nhất
int timMin(int a, int b, int c) {
    return min(min(a, b), c);
}

int main() {
    string x = "abcde";
	string y = "a1c2";

    int a[MAX][MAX];
    int n = x.length();
    int m = y.length();

	//Bảng phương án
	// a[i][0] = i
	// a[0][j] = j
	// x[i] = y[j] => a[i][j] = a[i-1][j-1] lấy từ chéo xuống
	// x[i] != y[j] => 
	//L[i][j] = max ( a[i-1][j], a[i][j-1], a[i-1][j-1] ) +1

	//3 cách biến đổi
	// Xoá x[i] => L[i,j]=L[i−1,j]+1.
	// Thay thế x[i] = y[j] => L[i,j]=L[i−1,j−1]+1 
	// Chèn y[j] vào sau x[i] => L[i,j]=L[i,j−1]+1

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0) {
                a[0][j] = j;
            } else if (j == 0) {
                a[i][0] = i;
            } else if (x[i - 1] == y[j - 1]) {
                a[i][j] = a[i - 1][j - 1];
            } else if (x[i - 1] != y[j - 1]) {
                a[i][j] = timMin(a[i - 1][j], a[i][j - 1], a[i - 1][j - 1]) + 1; //chọn phương án tối ưu nhất
            }
        }
    }

    cout << "\nBang truy vet:\n";
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "\nSo thao tac nho nhat la: " << a[n][m] << endl;

    // Truy vết - càng code càng bug :))
    int i = n;
    int j = m;
    vector<string> steps; //lưu truy vết

	// Nếu 2 ký tự giống nhau thì đi chéo lên và không làm gì cả
    // vì khi lập bảng truy vết ở trên khi 2 ký tự giống nhau
    // ta cũng chỉ gán a[i][j] = a[i - 1][j - 1] nên giờ đi ngược lại

	// Thứ tự ưu tiên là Xóa, Chèn, Thay thế nên ở if ta dùng <=
	// Cần đặt thứ tự ưu tiên vì truy truy vết lên có thể a[][] tại
	// 3 vị trí xóa, chèn, thay thế bằng nhau
	// => Cần chọn cái hợp lý nhất

	// Tại sao lại như vậy???
	// VD1: cần chuyển abc -> ab  => Xóa c
	// VD2: cần chuyển ab -> abc
	// nếu a[][] tại chèn và thay thế bằng nhau
	// thì ta hoàn toàn có thể chọn thay thế ở đây
	// ab' ' thay thế ' ' thành c
	// => Không hợp lý phải ko...
	// Hợp lý nhất là chèn c vào cuối
	// => Chèn có độ ưu tiên cao hơn thay thế
    for (int k = 1; k <= a[n][m]; ++k) {
        char s1 = x[i - 1];
        char s2 = y[j - 1];
        if (x[i - 1] == y[j - 1]) {
            i = i - 1;
            j = j - 1;

            --k; // đi chéo lên không được tính là 1 bước nên --k
        } else {
            string type;
            if (j == 0) {
                // Khi j bằng 0 ta chỉ việc xóa các ký tự còn lại
                type = "Xoa";
            } else if (i == 0) {
				// Khi i bằng 0 ta chỉ việc chèn các ký tự còn lại
                type = "Chen";
            } else {
                type = "Thay the";
                int min = a[i - 1][j - 1];

				//tìm xem cái nào tối ưu hơn thay thế?
                if (a[i][j - 1] <= min) {
                    min = a[i][j - 1];
                    type = "Chen";
                }

                if (a[i - 1][j] <= min) {
                    min = a[i - 1][j];
                    type = "Xoa";
                }
            }

            if (type == "Xoa") {
                steps.push_back(type + " " + x[i - 1] + "\n");
                i = i - 1;
            } else if (type == "Chen") {
                steps.push_back(type + " " + y[j - 1] + "\n");
                j = j - 1;
            } else if (type == "Thay the") {
                steps.push_back(type + " " + x[i - 1] + " = " + y[j - 1] + "\n");
                i = i - 1;
                j = j - 1;
            }
        }
    }

    for (int i = steps.size() - 1; i >= 0; --i) {
        cout << steps.at(i);
    }

    return 0;
}