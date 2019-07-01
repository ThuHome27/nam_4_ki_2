/*input
6 10
1 2 3 4 5 6
*/

#include <iostream>
#include <stack>
#define MAXN  21

using namespace std;

int n, M, m[MAXN], a, b, n_sol = 0;
bool used[MAXN], used_b[MAXN];

void _try_b(int k) {
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			used[i] = true;
			b += m[i];
			if (b == a) {
				++n_sol;
				// continue;
			}
			else if ((b < a) && (k <= n - 1)) {
				_try_b(k + 1);
			}
			
			b -= m[i];
			used[i] = false;
		}
	}

}


void _try_a(int k) {
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			used[i] = true;
			// int v = m[i];
			a += m[i];
			b = 0;
			// _reset_use_b();
			_try_b(1);

			if (k < n) {
				_try_a(k + 1);
			}

			a -= m[i];
			used[i] = false;
		}
		
	}
}

// void _reset_use_b () {
// 	b = 0;
// 	for (int i = 0; i < n; ++i) {
// 		used_b[i] = false;
// 	}
// }


int main(int argc, char const *argv[])
{
	cin >> n >> M;
	for (int i = 0; i < n; ++i) {
		cin >> m[i];
	}
	// m[0] = 0;
	// for (int i = 0; i < n; ++i) {
	// 	used[i] = false;
	// }
	// a = M; b = 0;

	// _try_b(1);

	for (int i = 0; i < n; ++i) {
		used[i] = false;
	}
	a = M; b = 0;
	_try_a(1);
	cout << n_sol;
	return 0;
}