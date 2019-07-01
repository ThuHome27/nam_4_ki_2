/*input
8 14
1 3 1
1 6 8
1 7 1
1 8 1
2 4 6
2 5 2
2 6 5
3 5 1
3 6 1
5 6 1
6 4 7
7 4 1
7 8 2
4 8 3
*/
#include <iostream>
#include<bits/stdc++.h> //sort
#define MAX 1001 // attention

using namespace std;

int n, m;
// int u[MAX], v[MAX], c[MAX];
int _rank[MAX];
int p[MAX];

struct edge
{
	int v1, v2, c;
};

edge edge_set[MAX];

void link(int x, int y) {
	if (_rank[x] > _rank[y]) {
		p[y] = x;
	}
	else {
		p[x] = y;
		if (_rank[x] == _rank[y]) _rank[y] += 1;
	}
}

void makeSet(int x) {
	p[x] = x;
	_rank[x] = 0;
}

int findSet(int x) {
	if (x != p[x]) {
		p[x] = findSet(p[x]);
	}
	return p[x];
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int iu, iv, ic;
		cin >> iu >> iv >> ic;
		edge_set[i].v1 = iu;
		edge_set[i].v2 = iv;
		edge_set[i].c = ic;
	}
}

bool cmp_sort(edge e1, edge e2) {
	return (e1.c < e2.c);
}

void call_quickSort() {
	sort(edge_set, edge_set + m, cmp_sort);
}


void solve() {
	for (int x = 1; x <=m; ++x) {
		makeSet(x);
	}
	// cout << 5;
	call_quickSort();
	int rs = 0, count = 0;
	for (int i = 0; i < m; ++i) {
		int ru = findSet(edge_set[i].v1);
		int rv = findSet(edge_set[i].v2);
		if (ru != rv) {
			link(ru, rv);
			rs += edge_set[i].c;
			++count;
			if (count == n-1) break;
		}
		// cout << rs;
	}
	cout << rs;
}

int main(int argc, char const *argv[])
{
	input();
	solve();
	return 0;
}