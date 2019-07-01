#include <iostream>
#define MAXN 10001

using namespace std;

int n, a[MAXN], scores[MAXN];
bool visit[MAXN];

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		// scores[i] = 0;
		// visit[i] = false;
	}			

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[j] < a[i]) ++scores[i];
		}
	}

	int max_sc = 0;
	for (int i = 1; i < n; ++i) {
		if (max_sc < scores[i]) max_sc = scores[i];
	}

	cout << max_sc;

	return 0;
}
