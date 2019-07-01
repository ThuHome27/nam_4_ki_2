/*input
6 12
3 2 7 5 2 3
*/

#include <iostream>
#include <stdio.h>
#define MAXN  31

using namespace std;

int n,b, a[MAXN], sum = 0, min = 999999999, max = -999999999;
int sign[2], n_sol = 0;


void _try(int k) {
	for (int i = 0; i < 2; ++i) {
		int v = sign[i];
		sum += v * a[k];

		int _max = sum, _min = sum;
		for (int j = k + 1; j < n; ++j) {
			_max += a[j];
			_min -= a[j];
		}
		if ( (_max < b) || (_min > b)) {
			sum -= v * a[k];
			continue;
		}

		if (k == n-1) {
			if (sum == b) {
				++n_sol;
			}
		}
		else {
			_try(k + 1);
		}
		sum -= v * a[k];
	}
}

int main(int argc, char const *argv[])
{
	// cin >> n >> b;
	scanf("%d %d", &n, &b);
	for (int i = 0; i < n; ++i) {
		// cin >> a[i];
		scanf("%d", a+i);
		// if (a[i] < min) {
		// 	min = a[i];
		// }
		// else if (a[i] > max) {
		// 	max = a[i];
		// }
	}

	sum = a[0];
	sign[0] = -1; sign[1] = 1;

	_try(1);

	// cout << n_sol % 1000000007;
	printf("%d", n_sol % 1000000007);
	return 0;
}