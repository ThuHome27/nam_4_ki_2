/*input
1000000000
1000000000
*/

#include <stdio.h>
#define MOD 1000000007

int a, b;
// long long int c;

int main(int argc, char const *argv[])
{
	scanf("%d %d", &a, &b);
	a %= MOD;
	b %= MOD;
	int z = MOD - a;
	if (z > b) {
		printf("%d", a + b);
	}
	else {
		printf("%d", b - z);
	}
	// printf("%d", c % MOD);
	return 0;
}