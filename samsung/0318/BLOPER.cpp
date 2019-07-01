/*input
2
9 5
5 6
*/

#include <iostream>
using namespace std;

int t, n, s;

int main(int argc, char const *argv[])
{
	cin >> t;
	while (t-- > 0) {
		cin >> n >> s;
		int sum = (1 + n) * n / 2;
		if (((sum & 1) ^ (s & 1)) == 1) {
			cout << 0 << '\n';
			continue;
		}

		cout << 1 << '\n';
	}
	return 0;
}