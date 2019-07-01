/*input
7 6
1 4
1 6
2 5
3 4
3 6
4 6
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXN 10

using namespace std;

vector<int> ke[MAXN];
bool duyet[MAXN];
int n, m;

void dfs(int u) {
	duyet[u] = true;
	// cout << u <<' ';
	for (int i = 0; i < ke[u].size(); ++i) {
		int v = ke[u][i];
		if (!duyet[v]) {
			// duyet[v] = true;
			dfs(v);
		}
	}
}

int main()
{	
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}

	for (int i = 0; i < n; ++i) {
		duyet[i] = false;
	}	

	// dfs(5);

	//connected components
	int n_com = 0;
	for (int i = 0; i < n; ++i) {
		if (!duyet[i]) {
			++n_com;
			dfs(i);
			cout << '\n';
		}
	}
	cout << n_com;

	return 0;
}