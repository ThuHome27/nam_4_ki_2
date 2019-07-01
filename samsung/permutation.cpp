#include <iostream>
#include <cstdlib> 
#include <string.h>
#include <queue>

using namespace std;

int n, x[1000], cnt = 0;
queue<int> num;

bool check (int v, int k) {
	return true;
}

void solution () {
	++cnt;
	cout << '\n';
	for (int i = 0; i < n; ++i) {
		cout << x[i];
	}
}

void tryy(int k) {
	for (int i = 0; i < num.size(); ++i) {
		int v = num.front();
		num.pop();
		if (check(v, k)) {
			x[k] = v;
			if (k == (n - 1)) solution();
			else {
				tryy(k + 1);
			}
		}
		num.push(v);
	}
}

void showq(queue <int> gq) 
{ 
    queue <int> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.front(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		num.push(i + 1);
	}
//	showq(num);	
	tryy(0);
	cout << cnt;
	return 0;
}
