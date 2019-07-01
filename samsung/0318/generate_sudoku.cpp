#include <iostream>

using namespace std;

int x[8][8], cnt, num_test;
bool mr[8][10], mc[8][10];
int m[2][2][10];

bool check(int v, int r, int c) {
	//
	if (mr[r][v]) return false;
	if (mc[c][v]) return false;
	if (m[r / 4][c / 4][v] > 1) return false;
	return true;
}

void solution() {
	++cnt;
	cout << "YES" << '\n';
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cout << x[i][j] << ' ';
		}
		cout << '\n';
	}
}

void tryy(int r, int c) {
	if (cnt > 5) return;
	// if (x[r][c] != 0) {
		// if (!check(x[r][c], r, c)) {
		// 	return; 
		// }
		// mr[r][x[r][c]] = true;
		// mc[c][x[r][c]] = true;
		// m[r / 4][c / 4][x[r][c]] += 1;
	// }
	if (x[r][c] == 0) {
		int v;
		for (v = 1; v <= 8; ++v) {
			if (check(v, r, c)) {
				x[r][c] = v;
				// update
				mr[r][v] = true;
				mc[c][v] = true;
				m[r / 4][c / 4][v] += 1;
				//
				if (r == 7 and c == 7) {
					solution();
				}
				else {
					if (c == 7) {
						tryy(r + 1, 0);
					}
					else {
						tryy(r, c + 1);
					}
				}
				// recover
				mr[r][v] = false;
				mc[c][v] = false;
				m[r / 4][c / 4][v] -= 1;
			}
		}
		x[r][c] = 0;
	}
	else {
		if (r == 7 and c == 7) {
			solution();
		}
		else {
			if (c == 7) {
				tryy(r + 1, 0);
			}
			else {
				tryy(r, c + 1);
			}
		}
	}
	
}

void init() {
	cnt = 0;
	for (int i = 0; i < 8; ++i) {
		for (int v = 1; v <= 9 ; ++v) {
			mr[i][v] = false;
			mc[i][v] = false;			
		}
	}
	//
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int v = 1; v <= 9 ; ++v) {
				m[i][j][v] = 0;		
			}
		}
	}

	// for (int i = 0; i < 8; ++i) {
	// 	for (int j = 0; j < 8; ++j) {
	// 		x[i][j] = 0;
	// 	}
	// }	
}

int main(int argc, char const *argv[])
{
	// cin >> num_test;
	// for (int t = 1; t <= num_test; ++t) {
	// 	cout << "Test case #" << t << ": ";
	// 	init();

	// 	for (int r = 0; r < 8; ++r) {
	// 		if (cnt == -1) {
	// 			break;
	// 		}
	// 		for (int c = 0; c < 8; ++c) {
	// 			cin >> x[r][c];

	// 			if (x[r][c] != 0) {
	// 				if (!check(x[r][c], r, c)) {
	// 					cnt = - 1;
	// 					break; 
	// 				}
	// 				mr[r][x[r][c]] = true;
	// 				mc[c][x[r][c]] = true;
	// 				m[r / 4][c / 4][x[r][c]] += 1;
	// 			}
	// 		}
	// 	}

	// 	if (cnt == - 1) {
	// 		cout << "NO" <<'\n';
	// 		continue;
	// 	}
		
	// 	tryy(0, 0);
	// }
	init();
		tryy(0, 0);
	return 0;
}