/*input
10 18
5 1
5 6
1 6
1 2
6 2
6 7
2 7
2 3
2 4
2 10
7 3
8 2
8 4 
8 9
4 9
4 10
10 9
3 10
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#define MAXN 100

using namespace std;

vector<int> ke[MAXN], res;
bool duyet[MAXN];
int n, m, id[MAXN];

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

	while (res.size() != n) {
		for (int i = 1; i <=n; ++i) {
			if (id[i] == 0 && !duyet[i] ) {
				duyet[i] = true;
				res.push_back(i);
				for (int j = 0; j < ke[i].size(); ++j) {
					--id[ke[i][j]];
				}
			}
		}		
	}


	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << ' ';
	}

	return 0;
}