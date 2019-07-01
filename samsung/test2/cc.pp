/*input
7
3 5 3 2 7 4 2
2 0 2 2 1 2
*/

#include <iostream>
#include <stack>
#define MAXN  100005

using namespace std;

int n, a[MAXN], b[MAXN], value = 0;
stack<int> stk;

void _print(stack<int> st) {
	while (st.size() != 0) {
		cout << st.top() << ' '; st.pop();
	}
	cout << '\n';
}

void _print_arr(int arr[]) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] <<' ';
	}
	cout << '\n';
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		cin >> b[i];
	}

// 	_print_arr(a);
// 	_print_arr(b);

	stk.push(a[0]);
	for (int i = 1; i < n; ++i) {
		stk.push(b[i]);
		stk.push(a[i]);
		if (b[i] == 2) {
			stk.pop();
			stk.pop();
			int x = stk.top();  stk.pop();
			stk.push(x * a[i]);
		}
// 		_print(stk);
	}

	// value = stk.top(); 
	while (stk.size() != 1 ){
		int y = stk.top(); stk.pop();
		int sign = stk.top(); stk.pop();
		// int x =  stk.top(); stk.pop();
		if (sign == 0) {
			sign = -1;
		}
		else {
			sign = 1;
		}
		// stk.push(sign *x +  y);
		value += sign * y;
// 		_print(stk);
	}

	// value = stk[0];
	// for (int i = 0; i < stk.size(); ++i) {
	// 	value += 
	// }

	// value = stk.top();
	cout << value + stk.top();
	return 0;
}