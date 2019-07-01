#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int n, a[MAX_N], si, res;

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	si = a[0]; res = a[0];
	for (int i = 1; i < n; ++i) {
		si = max(si + a[i], a[i]);
		res = max(si, res);
	}
	cout << res;
	return 0;
}