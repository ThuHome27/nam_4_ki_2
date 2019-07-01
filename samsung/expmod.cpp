/*input 
2
4
*/

#include <iostream>
using namespace std;

#define MOD 1000000007

int a, b, temp;

int add_mod(int x, int y, int mod) {
	int z = mod - x;
	if (z > y) return (x + y);
	return y - z;
}

int mul_mod_0(int _a, int _b, int mod) {
	// a %= mod;
	if (_b == 1) return a;
	if (_b == 0) return 0;
	int _temp = _a;
	while (_b-- > 1) {
		_temp = add_mod(_a, _temp, mod);
	}
	return _temp;
}

int mul_mod(int a, int b, int mod) {
	if (b == 0) return 0;
	if ((b & 1) == 1) return add_mod(a, mul_mod(a, b - 1, mod), mod);
	int t = mul_mod(a, b / 2, mod);
	return add_mod(t, t, mod);
}

int mpow(int x, int y) {
	if (y == 0) return 1;
	if ((y & 1) == 1) return mul_mod(x, mpow(x, y - 1), MOD);
	int t = mpow(x, y / 2);
	return mul_mod(t, t, MOD);
}

int main(int argc, char const *argv[])
{
	cin >> a >> b;
	a %= MOD;
	temp = a;
	if (b == 0) cout << 1;
	else if (b == 1) cout << a;
	else {
		cout << mpow(a, b);
	}
	return 0;
}