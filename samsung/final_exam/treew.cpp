/*input
7
4 3
3 5
5 1
1 2
2 7 
1 6
*/

#include <iostream>
#include <stdio.h>
#include <vector>
// #define MOD 1000000007
#define MAXN 100001
using namespace std;

struct edge
{
	int v;
	bool active;
};

vector<edge> ke[MAXN];
bool duyet[MAXN];
int n, m, cnt;



void dfs(int u) {
	duyet[u] = true;
	// cout << u <<' ';
	for (int i = 0; i < ke[u].size(); ++i) {
		edge e = ke[u][i];
		if (!e.active) continue;
		int v = e.v;
		if (!duyet[v]) {
			// duyet[v] = true;
			++cnt;
			dfs(v);
		}
	}
}

int main()
{	
	cin >> n;
	for (int i = 1; i <= n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		edge e;
		e.v = v; e.active = true; ke[u].push_back(e);
		e.v = u; e.active = true; ke[v].push_back(e);
	}

	int re = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < ke[i].size(); ++j) {
			ke[i][j].active = false;
			cnt = 0;
			for (int k = 1; k <= n; ++k) {
				duyet[k] = false;
			}
			dfs(i);
			re += (cnt + 1) * (n - cnt - 1);
			// cout << cnt <<' ' << re << '\n';
			ke[i][j].active = true;
		}
	}
	
	cout << re / 2;

	return 0;
}