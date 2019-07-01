//
// Created by tony on 2/28/19.
//
#include <iostream>
using namespace std;

int n, i, c, t, h, u, k, s;
int x[7], cnt = 0;
bool is_appare[9];

bool check(int i, int c, int t, int h, int u, int k, int s) {
    if (1000 * h + 100 * (i - k + u) + 10 * (c + s) + t * 2 - 62 == n) {
        return true;
    }
    return  false;
}

void solution() {
    ++cnt;
//    for (int i = 0; i < 7; ++i) {
//        cout << x[i] << ' ';
//    }
//    cout << '\n';
}

void tryy(int k) {
    for (int i = 1; i <= 9; ++i) {
        if (!is_appare[i]) {
            is_appare[i] = true;
            x[k] = i;
            if (k == 6) {
                if (check(x[0], x[1], x[2], x[3], x[4], x[5], x[6])) {
                    solution();
                }
            }
            else {
                tryy(k + 1);
            }
            is_appare[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 10; ++ i) {
        is_appare[i] = false;
    }
//    cout << "before";
    tryy(0);
    cout << cnt;
    return 0;
}