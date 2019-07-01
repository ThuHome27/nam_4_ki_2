/*input
6
0 4 2 3 5 4 4
4 0 7 5 2 3 1
3 2 0 1 2 1 9
2 3 5 0 9 8 3
2 1 4 6 0 9 1
9 8 1 4 2 0 8
1 2 3 2 5 4 0
*/

#include <iostream>
#include <stdio.h>
#define MOD 1000000007
#define MAXN 21
using namespace std;

int n, a[MAXN][MAXN], amin, best, cost;
bool visit[MAXN];

bool check(int k) {
	if (visit[k]) return false;
	if (k > n/2) {
		if (!visit[k - n/2]) return false; 
	}
	return true;
}

// void update_best()
void mtry(int k, int parent) {
	for (int i = 1; i <= n; ++i) {
		if (check(i)) {
			visit[i] = true;
			cost += a[parent][i];
			if (cost + amin * (n - k + 1) < best) {
				if (k == n) {
					if (cost + a[i][0] < best)  
						best = cost + a[i][0];
				}
				else {
					mtry(k + 1, i);
				}
			}
			cost -= a[parent][i];
			visit[i] = false;
		}
	}
}


int main(int argc, char const *argv[])
{
	// cin >> n;
	scanf("%d", &n);
	n = n / 2;
	amin = 999999999;
	best = 999999999;
	cost = 0;
	for (int i = 0; i < 2*n+1; ++i) {
		for (int j = 0; j < 2*n+1; ++j) {
			// cin >> a[i][j];
			int temp;
			scanf("%d", &temp);
			a[i][j] = temp;
			if (a[i][j] < amin) {
				amin = a[i][j];
			}
		}
	}
	n *= 2;
	for (int i = 1; i <= n; ++i) {
		visit[i] = false;
	}

	mtry(1, 0);
	// cout << best;
	printf("%d\n", best);
	return 0;
}