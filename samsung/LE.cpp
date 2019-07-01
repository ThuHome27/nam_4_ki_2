/*input 
2 20
2 3
*/
#include <iostream>
#include <cstdlib> 
#include <string.h>

using namespace std;

int n, m, cnt  = 0, a[11], x[11];
int sum_till_present = 0;
int sum_a_left = 0; // a[k + 1] + ... + a[n]

bool check(int v, int k) {
	return true;
}

void solution() {
	++cnt;
}

void tryy(int k) {
	// printf("%d\n", k);
	sum_a_left -= a[k];
	int max_v = (m - sum_till_present - sum_a_left) / a[k];
	for (int i = 1; i <= max_v; ++i) {
		int v = i;
		if (check(v, k)) {
			// printf("%d ", v);
			x[k] = v;
			sum_till_present += x[k] * a[k];
			if (k == (n - 1)) {
				if (sum_till_present == m) solution();
			}
			else {
				tryy(k + 1);
			}
			sum_till_present -= x[k] * a[k];
		}
	}
	sum_a_left += a[k];
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum_a_left += a[i];
	}
	// sum_a_left -= a[0];

	 tryy(0);
	cout << cnt;
	return 0;
}
