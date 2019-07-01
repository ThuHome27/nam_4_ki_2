//
// Created by tony on 2/24/19.
//

#include <iostream>
using namespace std;
#define MAX_N 1000

int n, x[MAX_N], sum_left;

bool check(int k) {
    return true;
}

void solution(int k) {
    for (int i = 0; i <= k; ++i) {
        cout << x[i] << ' ';
    }
    cout << '\n';
}

void tryy(int k, int pre_x) {
//    cout << '\n' << "k = " << k << "pre_x = " << pre_x;
    int max_v = sum_left / 2;
//    cout << "max v " << max_v;
    for (int v = pre_x; v <= max_v; ++v) {
//        cout << "v = " << v << "k = " << k << "max_v = " << max_v;
        if (check(v)) {
            x[k] = v;
            sum_left -= v;
            if (v > sum_left / 2) {
                x[k + 1] = sum_left;
                solution(k + 1);
            }
            else {
                tryy(k + 1, v);
            }
        }
        sum_left += v;
    }
    //
    x[k] = sum_left;
    solution(k);
}

void init() {
    cin >> n;
    sum_left = n;
}


int main() {
    init();
    tryy(0, 1);
    return 0;
}
