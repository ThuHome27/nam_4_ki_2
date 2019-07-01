#include <iostream>

using namespace std;

int x[9][9], cnt;
bool mr[9][10], mc[9][10], m[3][3][10];

bool check(int v, int r, int c) {
	//
	if (mr[r][v]) return false;
	if (mc[c][v]) return false;
	if (m[r / 3][c / 3][v]) return false;
	return true;
}

void solution() {
	++cnt;
	cout << cnt << '\n';
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << x[i][j] << ' ';
		}
		cout << '\n';
	}
}

void tryy(int r, int c) {
	if (cnt > 10) return;
	int v;
	for (v = 1; v <= 9; ++v) {
		if (check(v, r, c)) {
			x[r][c] = v;
			// update
			mr[r][v] = true;
			mc[c][v] = true;
			m[r / 3][c / 3][v] = true;
			//
			if (r == 8 and c == 8) {
				solution();
			}
			else {
				if (c == 8) {
					tryy(r + 1, 0);
				}
				else {
					tryy(r, c + 1);
				}
			}
			// recover
			mr[r][v] = false;
			mc[c][v] = false;
			m[r / 3][c / 3][v] = false;
		}
	}
}

void init() {
	cnt = 0;
	for (int i = 0; i < 9; ++i) {
		for (int v = 1; v <= 9 ; ++v) {
			mr[i][v] = false;
			mc[i][v] = false;			
		}
	}
	//
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int v = 1; v <= 9 ; ++v) {
				m[i][j][v] = false;		
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	init();
	tryy(0, 0);
	return 0;
}