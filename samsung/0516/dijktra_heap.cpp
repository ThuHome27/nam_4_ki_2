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


void _print_arr(int arr[]) {
	for (int i = 1; i <= n; ++i) {
		cout << arr[i] <<' ';
	}
	cout << '\n';
}

/////////////////////////////////////////////////
int v_index[MAXV], cur_size;

struct node
{
	int v;
	int key;
};

node mheap[MAXV];

void print_heap(int size) {
	for (int i = 1; i <= size; ++i) {
		cout << mheap[i].v << ' ' << mheap[i].key << '\n';
	}
	cout << '\n';
}

void swap(int nid_1, int nid_2) {
	int tv = mheap[nid_1].v, tk = mheap[nid_1].key;
	mheap[nid_1].v = mheap[nid_2].v; mheap[nid_1].key = mheap[nid_2].key; 
	mheap[nid_2].v = tv, mheap[nid_2].key = tk;
}

void down_heap(int node_id, int size) {
	node cur_node = mheap[node_id];
	v_index[cur_node.v] = node_id;
	if (2 * node_id > size) return;
	int select_id;
	node select_nod;
	node left_child = mheap[2 * node_id];
	select_id = 2 * node_id;
	select_nod = left_child;
	if (2 * node_id + 1 <= size) {
		node right_child = mheap[2 * node_id + 1];
		if (left_child.key > right_child.key) {
			select_id = 2 * node_id + 1;
			select_nod = right_child;
		}
	}

	if (select_nod.key < cur_node.key) {
		swap(select_id, node_id);
		down_heap(select_id, size);
	}
}

void up_heap(int node_id) {
	node cur_node = mheap[node_id];
	v_index[cur_node.v] = node_id;
	if (node_id / 2 == 0) return;
	node parent_n = mheap[node_id / 2];
	if (cur_node.key < parent_n.key) {
		swap(node_id, node_id / 2);
		up_heap(node_id/2);
	}
}

void build_heap() {
	int k = 0;
	for (int i = 1; i <= n; ++i) {
		++k;
		if (i == s) {
			--k;
		}
		else {
			mheap[k].v = i;
			mheap[k].key = d[i];
			up_heap(k);
		}
		// print_heap(k);
	}
}

void update_d(int v, int value) {
	d[v] = value;
	mheap[v_index[v]].key = value;
	up_heap(v_index[v]);
}

int get_min() {
	int re = mheap[1].v;
	swap(mheap[1], mheap[cur_size]);
	--cur_size;
	down_heap(1, cur_size);
	return re;
}
//////////////////////////////////////////////////////


void _input() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a;
		edg e;
		cin >> e._v >> e._w;
		w[a].push_back(e);
	}
	cin >> s >> f;
}

void _init() {
	d[s] = 0;
	cur_size = n - 1;

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

	build_heap();
}

int main(int argc, char const *argv[])
{
	_input();
	_init();
		_print_arr(d);
		_print_arr(p);
	while (cur_size > 1) {
		int v = get_min(); 
		// cout << v << '\n';
		for (int i = 0; i < w[v].size(); ++i) {
			edg e = w[v][i];
			if (d[e._v] > d[v] + e._w) {
				update_d(e._v, d[v] + e._w);	// d[e._v] = d[v] + e._w;
				p[e._v] = v;
			}
		}		

		// _print_arr(d);
		// _print_arr(p);
	}


	cout << d[f];
	// cout << f;

	return 0;
}