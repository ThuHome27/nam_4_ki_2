/*input
6 4 2
*/

#include <iostream>
#define MAXN 10001

using namespace std;

int n, k, y;
int zero[MAXN], kq[MAXN];
int cnt = 0;
bool fin = false;

bool _check(int v, int t) {
	if (v == 1) {
		return true;
	}
	if (zero[t] >= y - 1) {
		return false;
	}
	return true;
}

void _update(int v, int t) {
	if (t == n-1) return;
	if (v == 0) {
		zero[t + 1] = zero[t] + 1;
	}
	else {
		zero[t + 1] = 0;
	}
}

void _try(int t) {
	if (fin) return;
	for (int v = 0; v <=1; ++v) {
		if (_check(v, t)) {
			kq[t] = v;
			_update(v, t);
			if (t == n-1) {
				++cnt;
				if (cnt == k) {
					for (int i = 0; i < n; ++i) {
						cout << kq[i] << ' ';
						fin = true;
					}
					// cout << '\n';
					// for (int i = 0; i < n; ++i) {
					// 	cout << zero[i] << ' ';
					// }
				}
			}
			else {
				_try(t + 1);
			}

		}
	}
}

int main(int argc, char const *argv[])
{
	cin >> n >> k >> y;
	for (int i = 0; i < n; ++i) {
		zero[i] = 0;
	}
	_try(0);
	if (!fin) {
		cout << -1;
	}
	return 0;
}