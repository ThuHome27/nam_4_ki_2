//
// Created by tony on 2/28/19.
//

#include <iostream>
using namespace std;

int n, s, x[99], sum = 0, cnt = 0;
int re[99];

void solution(int k) {
    ++cnt;
//    for (int i = 0; i <= k; ++i) {
//        cout << re[i] << ' ';
//    }
//    cout << '\n';
}

void tryy(int k, int j) {
    for (int i = j; i < n; ++i) {
        if (sum + x[i] == s) {
            re[k] = x[i];
            solution(k);
        }
        else if (sum + x[i] < s) {
            re[k] = x[i];
            sum += x[i];
            if (k < n - 1) {
                tryy(k + 1, i + 1);
            }
            sum -= x[i];
        }
    }
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    tryy(0, 0);
    cout << cnt;
    return  0;
}