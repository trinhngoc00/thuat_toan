#include <iostream>
using namespace std;

void quickSort(int a[], int left, int right) {
	int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    // Phải dùng <= ở while và if:
    // Vì ở if bên dưới sẽ ++i, --j
    // nên khi đệ quy quickSort sẽ không có sort mảng chứa pivot nữa
    // VD: Mảng: 2 4 3 1 5 (pivot = 3)
    // Sau vòng while ta được mảng: 2 1 3 4 5
    // Ta sẽ chỉ gọi đệ quy cho 2 mảng con là: 2 1 và 4 5
    while (i <= j) {
        while (a[i] < pivot) {
            ++i;
        }

        while (a[j] > pivot) {
            --j;
        }

        if (i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        } //khi i=j, i++, j-- để kết thúc while
    }

    if (left < j) quickSort(a, left, j);
    if (right > i) quickSort(a, i, right);
}

// CTDL Heap là gì? là một trường hợp đặc biệt của cấu trúc dữ liệu cây nhị phân cân bằng
// Max-Heap: ở đây giá trị của nút gốc là lớn hơn hoặc bằng giá trị của các nút con.
void pushDown(int a[], int i, int n) {
	int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // left < n: để đảm bảo con trái không vượt quá mảng
    if (left < n && a[left] > a[root]) {
        root = left;
    }

    // right < n: để đảm bảo con phải không vượt quá mảng
    if (right < n && a[right] > a[root]) {
        root = right;
    }

    // Sau 2 lệnh if thì index của root sẽ là index của con lớn nhất
    if (root != i) {
        swap(a[i], a[root]);
        // Đệ quy tiếp tục với cây con
        pushDown(a, root, n);
    }
}
void heapSort(int a[], int n) {
	// Bước 1: Xây dựng Max-Heap
    // Vòng lặp chạy từ i = n / 2 - 1 đến 0
    // VD: n = 5 => i = 1, 0
    // Tại sao lại lặp có 2 lần?
    // Vì 1 cây nhị phân chỉ có n / 2 gốc mà thôi
    // mà index của mảng start từ 0 -> for n/2-1 tới 0
    // Vậy tạo sao lại chạy từ i = n/2-1 về 0 mà không phải từ 0 đến n/2-1
    // Vì ta cần phải tạo max-heap từ cây con ở phía dưới trước,
    // xong cây con ở phía dưới rồi mới đến gốc của cây con đó
    for (int i = n / 2 - 1; i >= 0; --i) {
        pushDown(a, i, n);
    }
    // Bước 2: Đưa phần tử lớn nhất về cuối mảng và loại nó ra khỏi heap
    // và lặp lại đến khi mảng được sắp xêp
    for (int i = n - 1; i > 0; --i) {
        // Đổi chỗ phần tử đầu(phần tử lớn nhất) với phần tử cuối mảng
        swap(a[0], a[i]);

        // Phần tử cuối đã là lớn nhất, ta không cần xét nữa
        // Tạo lại max-heap (không chứa phần tử cuối)
        // pushDown lại bắt đầu từ 0 (gốc) mà không phải dùng for từ cây con như
        // trên vì các cây con vẫn là max-heap chỉ có gốc bị đổi nên chỉ cần
        // pushDown từ gốc là được
        pushDown(a, 0, i);
        // dùng i > 0 mà không phải i >= 0 vì khi i == 0 thì lúc đó cây chỉ còn
        // 1 phần tử nên không cần phải đổi chỗ làm gì cả => dùng i > 0
    }
}

void merge(int a[], int left, int mid, int right) { //gộp 2 mảng L,R đã có thứ tự
	//chia từ mid, mảng L có thể hơn mảng R 1 phần tử
	int n1 = mid - left + 1; 	//số phần tử của mảng con trái L
    int n2 = right - mid; 		//số phần tử của mảng con phải R

    int L[n1];
    int R[n2];

    // Copy a sang 2 mảng L, R (tách mảng a thành 2 mảng L, R)
	//mảng L: chỉ số trong a <= mid, mảng R: >= mid +1
    for (int i = 0; i < n1; ++i) {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; ++j) { 
        R[j] = a[mid + 1 + j];
    }

    int i = 0;	//chỉ số mảng L
    int j = 0;	//chỉ số mảng R
    int k = left;	//chỉ số mảng a khi gộp từ L, R, bắt đầu từ vị trí left

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) { //phần từ mảng trái < phải -> a[k] = phần tử mảng trái
            a[k] = L[i];
            ++i;	//tăng chỉ số mảng trái
        } else {
            a[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Mảng R đã hết, chỉ còn mảng L, dồn tất cả các phần tử còn lại của L vào a
    while (i < n1) {
        a[k] = L[i];
        ++i;
        ++k;
    }

    // Hoặc mảng L đã hết, chỉ còn mảng R, dồn tất cả các phần tử còn lại của R vào a
    while (j < n2) {
        a[k] = R[j];
        ++j;
        ++k;
    }
}
void mergeSort(int a[], int left, int right) {
	// Chỉ sort mảng có từ 2 phần tử trở lên
	// chia mảng a thành 2 mảng từ mid đến khi thành những mảng chỉ có 1 phần tử, sau đó trộn với nhau thành mảng có thứ tự
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

int main() {
	int s[] = {3, 2, 10, 5, 8, 4, 7};
  	int n = sizeof(s) / sizeof(s[0]);

	//quickSort(s, 0, n-1);
	//heapSort(s, n);
	mergeSort(s, 0, n - 1);

	cout<<"\nSap xep tang dan:";
	for (int i = 0; i < n; ++i) {
    	cout << s[i] << "\t";
  	}	

	return 0;
}