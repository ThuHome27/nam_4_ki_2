/*input
4
2
2 1
3 1
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h> 
#define MAXN 100

using namespace std;

vector<int> ke[MAXN];
bool duyet[MAXN];
int n, m, id[MAXN], cnt;
stack<int> res;
int x[MAXN];

void print_res() {
	while (res.size() != 0) {
		cout << res.top();
		res.pop();
	}
}

// void _try(int u) {
// 	duyet[u] = true;
// 	res.push(u);
// 	for (int i = 0; i < ke[u].size(); ++i) {
// 		--id[ke[u][i]];
// 	}
// 	if (res.size() == n) {
// 		++cnt;
// 		// print_res();
// 		return;
// 	}

// 	for (int i = 1; i <= n; ++i) {
// 		if (id[i] == 0 && !duyet[i] ) {
// 			_try(i);
// 		}
// 	}
// 	//
// 	duyet[u] = false;
// 	for (int i = 0; i < ke[u].size(); ++i) {
// 		++id[ke[u][i]];
// 	}
// 	res.pop();
// }

void solution() {
	++cnt;
	// for (int i = 1; i <= n; ++i) {
	// 	cout << x[i] << ' ';
	// }
	// cout << '\n';
}


void _try(int k) {
	for (int i = 1; i <= n; ++i) {
		if (id[i] == 0 && !duyet[i] ) {
			x[k] = i;
			if (k == n) {
				solution();
			}
			else {
				duyet[i] = true;
				for (int j = 0; j < ke[i].size(); ++j) {
					--id[ke[i][j]];
				}
				_try(k + 1);
				duyet[i] = false;
				for (int j = 0; j < ke[i].size(); ++j) {
					++id[ke[i][j]];
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		id[i] = 0;
		duyet[i] = false;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		ke[u].push_back(v);
		id[v] += 1;
	}

	cnt = 0;
	_try(1);
	cout << cnt;

	return 0;
}