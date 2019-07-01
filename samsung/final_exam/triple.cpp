/*input
5 10
3 2 4 5 1
*/

#include <iostream>
#define MOD 1000000007
#define MAXN 10001
using namespace std;

int n, a[MAXN], m;

// void mtry()

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int re = 0;
	for (int i = 0; i < n-2; ++i) {
		int s = a[i];
		if (s <= m) {
			for (int j = i + 1; j < n-1; ++j) {
				s += a[j];
				if (s <= m) {
					for (int k = j + 1; k < n; ++k) {
						s += a[k];
						if (s == m) ++re;
						s -= a[k];
					}
				}
				s -= a[j];
			}			
		}
	}
	cout << re % MOD;
	return 0;
}