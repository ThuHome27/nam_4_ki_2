/*input
12 22
1 2
1 4
5 1
4 5
2 5
2 3
2 6
6 3
4 6
4 8
6 8
3 7
7 6
7 9
8 9
8 10
7 11
10 9
9 11
11 10
10 12
12 11
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#define MAXN 100

using namespace std;

vector<int> ke[MAXN], r_ke[MAXN];
bool duyet[MAXN];
int n, m, TIME = 0;
int f_visit[MAXN], sfv[MAXN], sfv_ind = -1;

// struct _time
// {
// 	int vetex, f_time;
// };

// _time  f_visit[MAXN];

/////////////////////////

// Compares two intervals according to finish times. 
// bool compareInterval(_time i1, _time i2) 
// { 
//     return (i1.f_time > i2.f_time); 
// }

void dfs(int u, int is_pr, vector<int> ke[]) {
	++TIME;
	duyet[u] = true;
	if (is_pr) cout << u << ' ';
	// cout << u <<' ';
	for (int i = 0; i < ke[u].size(); ++i) {
		int v = ke[u][i];
		if (!duyet[v]) {
			// duyet[v] = true;
			dfs(v, is_pr, ke);
		}
	}
	//
	++TIME;
	f_visit[u] = TIME;	
	++sfv_ind;
	sfv[sfv_ind] = u;
	// f_visit[u].vetex = u;
	// f_visit[u].f_time = TIME;
}

int main()
{	
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		ke[u].push_back(v);
		r_ke[v].push_back(u);
		// ke[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		duyet[i] = false;
	}	

	for (int i = 1; i <= n; ++i) {
		if (!duyet[i]) {
			dfs(i, 0, ke);
		}
	}

	for (int i = 1; i <= n; ++i) {
		duyet[i] = false;
	}

	// for (int i = n-1; i >=0; --i) {
	// 	cout << sfv[i] << ' ' << f_visit[sfv[i]] << '\n';
	// }

	for (int i = n-1; i >=0; --i) {
		int t = sfv[i];
		if (!duyet[t]) {
			dfs(t, 1, r_ke);
			cout << '\n';
		}
	}



	return 0;
}