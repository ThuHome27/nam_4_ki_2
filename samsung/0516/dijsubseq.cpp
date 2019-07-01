/*input
5
2 3 -4 1 -5
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1001


int n, a[MAX_N], si, results[MAX_N];

int max_sub(int l, int r) {
	int si = a[l], res = a[l];
	for (int i = l+1; i <= r; ++i) {
		si = si > 0 ? si+a[i] : a[i]; 
		// si = max(si + a[i], a[i]);
		res = max(si, res);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n-1; ++i) {
		results[i] = max_sub(0, i) + max_sub(i+1, n-1);
	}

	int q = results[0];
	for (int i = 1; i < n - 1; ++i) {
		if (q < results[i]) q = results[i];
	}
	cout << q;
	return 0;
}