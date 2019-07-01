/*input
7 12
1 5 3
1 7 9
2 1 2
2 4 15
2 5 30
3 2 1
3 1 10
4 6 1
5 4 9
5 7 2
7 4 4
7 6 20
3 6
*/

#include <iostream>
#include <vector>
#define MAXC 100
#define MAXV 10
using namespace std;

int p[MAXV], d[MAXV];
int n, m, s, f, n_fix;
struct edg
{
	int _v;
	int _w;
};
vector<edg> w[MAXV];
// int w[MAXV][MAXV];
bool _fixed[MAXV];

void _print_arr(int arr[]) {
	for (int i = 1; i <= n; ++i) {
		cout << arr[i] <<' ';
	}
	cout << '\n';
}



int min_nonfix() {
	int _min = MAXC + 1;
	int re;
	for (int i = 1; i <= n; ++i) {
		if ((!_fixed[i]) && (d[i] < _min)) {
			_min = d[i];
			re = i;
		}
	}
	return re;
}

void _input() {
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		// cin >> a >> b >> c;
		// w[a][b] = c;
		cin >> a;
		edg e;
		cin >> e._v >> e._w;
		w[a].push_back(e);
	}

	cin >> s >> f;
}

void _init() {
	d[s] = 0;

	bool adj_of_s[MAXV];
	for (int i = 1; i <=n; ++i) {
		adj_of_s[i] = false;
	}
	for (int i = 0; i < w[s].size(); ++i) {
		edg e = w[s][i];
		d[e._v] = e._w;
		adj_of_s[e._v] = true;
	}
	for (int i = 1; i <= n; ++i) {
		if (!adj_of_s[i]) {
			d[i] = MAXC + 1;
		}
	}
}

struct node
{
	int v;
	int key;
};

void swap(node &a, node &b) {
	int tv = a.v, tk = a.key;
	a.v = b.v; 

}

node _heap[MAXV];



int main(int argc, char const *argv[])
{
	_input();
	_init();

		_print_arr(d);
		_print_arr(p);
// 	// _print_arr(d);

	for (int i = 1; i <=n; ++i) {
		_fixed[i] = false;
	}
	_fixed[s] = true;
// _print_arr(d);
	n_fix = 1;
	while (n_fix < n) {
		int v = min_nonfix(); 
		// cout << v << '\n';
		_fixed[v] = true;
		++n_fix;

		for (int i = 0; i < w[v].size(); ++i) {
			edg e = w[v][i];
			if (d[e._v] > d[v] + e._w) {
				d[e._v] = d[v] + e._w;
				p[e._v] = v;
			}
		}		

		_print_arr(d);
		_print_arr(p);
	}


	cout << d[f];
	// cout << f;

	return 0;
}