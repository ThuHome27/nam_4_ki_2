/*input
3
1 2
2 3
2 1
*/

#include <iostream>
#define MAXN 1001

using namespace std;

int a[MAXN], b[MAXN], maxa = -1, maxb = -1, result = 0, n;
// bool mark[MAXN];

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		a[i] = x;
		b[i] = y;
		// if (x > maxa) {
		// 	maxa = x;
		// }
		// if (y > maxb) {
		// 	maxb = y;
		// }
	}
	// for (int i = 0; i < n; ++i) {
	// 	mark[i] = false;
	// }

	// for (int i = 0; i < n; ++i) {
	// 	if (a[i] == maxa) {
	// 		++result;
	// 	}
	// 	else if (b[i] == maxb) {
	// 		++result;
	// 	}
	// }

	for (int i = 0; i < n; ++i) {
		bool check = true;
		for (int j = 0; j < n; ++j) {
			if ((a[j] > a[i]) && (b[j] > b[i]) ) {
				check = false;
				break;
			}
		}
		if (check) {
			++result;
		}
	}

	cout << result;

	return 0;
}