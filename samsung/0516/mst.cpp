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
#include <set>
#define MAX 1000001

using namespace std;

int n, m;
int u[MAX], v[MAX], c[MAX];
int _rank[MAX];
int p[MAX];

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
		u[i] = iu; 
		v[i] = iv;
		c[i] = ic;
	}
}

void swap(int &a, int &b) {
	int tmp = a; 
	a = b; b = tmp;
}

void swapEdge(int i, int j) {
	swap(c[i], c[j]);
	swap(u[i], u[j]);
	swap(v[i], v[j]);
}

int partition(int l, int r, int index) {
	int pivot = c[index];
	swapEdge(index, r);
	int storeIndex = l;
	for (int i = l; i < r-1; ++i) {
		if (c[i] < pivot) {
			swapEdge(storeIndex, i);
			++storeIndex;
		}
	}
	swapEdge(storeIndex, r);
	return storeIndex;
}

void quickSort(int l, int r) {
	if (l < r) {
		int index = (l + r) / 2;
		index = partition(l, r, index);
		if (l < index) {
			quickSort(l, index-1);
		}
		if (index < r) quickSort(index+1, r);
	}
}

void call_quickSort() {
	quickSort(0, m-1);
}


void solve() {
	for (int x = 1; x <=m; ++x) {
		makeSet(x);
	}
	// cout << 5;
	call_quickSort();
	int rs = 0, count = 0;
	for (int i = 0; i < m; ++i) {
		int ru = findSet(u[i]);
		int rv = findSet(v[i]);
		if (ru != rv) {
			link(ru, rv);
			rs += c[i];
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