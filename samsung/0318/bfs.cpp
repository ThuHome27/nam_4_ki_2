/*input
6 10
1 2
1 3
1 5
1 6
2 3
2 4
2 5
3 4
3 5
5 6
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAXN 100

using namespace std;

int n, m;
vector<int> adj[MAXN];
int p[MAXN];

int bfs_sp(int start, int end) {
	// shortest path
	--start; --end;
	int dis[MAXN];
	for (int i = 0; i < n; ++i) {
		dis[i] = 0;
	}
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			if (dis[v] == 0) {
				dis[v] = 1+ dis[u];
				p[v] = u;
				q.push(v);
			}
		}
	}

	return dis[end];
}

void pri_path(int start, int end) {
	// 
	--start; --end;
	int x = end;
	cout << x << ' ';
	while (x != start) {
		x = p[x];
		cout << x << ' ';
	}
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << bfs_sp(3, 6) << '\n';

	// pri_path(3, 6);
	// for (int i = 0; i < n; ++i) {
	// 	cout << p[i] <<' ';
	// }
		
	// cout << 

	return 0;
}