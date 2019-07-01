#include <iostream>
using namespace std;

#define MOD 1000000007

int a, b, temp;

int add_mod(int x, int y, int mod) {
	int z = mod - x;
	if (z > y) return (x + y);
	return y - z;
}

int main(int argc, char const *argv[])
{
	cin >> a >> b;
	a %= MOD;
	temp = a;
	while (b-- > 1) {
		temp = add_mod(a, temp, MOD);
	}
	cout << temp;
	return 0;
}