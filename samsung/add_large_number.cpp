/*input 
123
*/
#include <iostream>
#include <cstdlib> 
#include <string.h>

using namespace std;

int a, b, pos1, pos2, l1, l2, sublen1, sublen2;
// int end1, end2;
string s1, s2, sub1, sub2;
//string m1;


int main(int argc, char const *argv[])
{
	cin >> s1 >> s2;
	l1 = s1.size();
	l2 = s2.size();
	while ((l1 > 0) && (l2 > 0)) {
		if (l1 > 8) {
			l1 -= 8;
			sublen1 = 8;
		}
		else {
			sublen1 = l1;
			l1 = 0
		}
		if (l2 > 8) {
			l2 -= 8;
			sublen1 = 8;
		}
		else {
			sublen1 = l2;
			l2 = 0
		}
		sub1 = s1.substr(l1 - sublen1, sublen1);
	}
	// sub1 = s1.substr(0, 3);

	// a = atoi(s);
	// printf("%d\n", a + 1);
	cout << sub1;
	return 0;
}
