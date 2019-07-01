/*input
380
*/
#include <iostream>
using namespace std;

int n, a[] = {500, 100, 50, 10, 5, 1};
int result = 0, i = 0;

int main(int argc, char const *argv[])
{
	cin >> n;
	n = 1000 - n;
	while (n > 0) {
		result += n / a[i];
		n -= n / a[i] * a[i];
		++i;
	}
	cout << result;
	return 0;
}