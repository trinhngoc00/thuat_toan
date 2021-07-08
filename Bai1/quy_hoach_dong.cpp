// Dãy con ở đây là dãy liên tiếp
#include <iostream>
using namespace std;
const int MAX = 100;

/* Bảng phương án có dạng như sau
-2  9  5  18  13  15
 0  11 7  20  15  17
 0  0 -4  9   4   6
 0  0  0  13  8   10
 0  0  0  0  -5  -3
 0  0  0  0   0   2
*/

int main()
{
	int s[] = {-2, 11, -4, 13, -5, 2};
	int n = sizeof(s) / sizeof(s[0]);

	int a[MAX][MAX] = {0};

	// Lập bảng phương án
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
			{
				a[i][j] = s[i];
			}
			else if (j > i)
			{
				a[i][j] = a[i][j - 1] + s[j];
			}
		}
	}

	int tongMax = INT_MIN;
	int start = 0;
	int end = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j >= i && a[i][j] > tongMax)
			{
				tongMax = a[i][j];
				start = i;
				end = j;
			}
		}
	}

	cout << "Day con co tong lon nhat bang " << tongMax << " la: ";
	for (int i = start; i <= end; ++i)
	{
		cout << s[i] << "; ";
	}

	return 0;
}