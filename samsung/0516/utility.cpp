#include<bits/stdc++.h> //sort
#include <iostream>
#include<stdio.h>

using namespace std;

// bool cmp_sort(int a[3], int b[3]) {
// 	return (a[2] < b[2]);
// }


//////////////sort////////////////////
struct edge
{
	int v1, v2, c;
};

edge arr[100];

bool cmp_sort(edge e1, edge e2) {
	return (e1.c < e2.c);
}


////////////////binary search///////////////
int b_s (int x, int a[], int l, int r) {
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (a[m] == x) return m;
		else if (a[m] < x) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return -1;
}


int main(int argc, char const *argv[])
{
	// int n = 3;
	// arr[0].v1 = 1;
	// arr[0].v2 = 2;
	// arr[0].c  = 4;

	// arr[1].v1 = 1;
	// arr[1].v2 = 3;
	// arr[1].c  = 9;

	// arr[2].v1 = 4;
	// arr[2].v2 = 3;
	// arr[2].c  = 7;

	// // int arr[][3] = {{1, 2, 3}, {3, 2, 1}, {1, 22, 111}};
	// sort(arr, arr + n, cmp_sort);

	// for (int i = 0; i < n; ++i) {
	// 	cout << arr[i].v1 << ' ' << arr[i].v2 << ' ' << arr[i].c;
	// 	cout << '\n';
	// }

	////////////////binary search////////////////
	int arr[] = { 2, 3, 4, 10, 40, -1, 111, -1, 0, -33, 14, 1 }; 
    int x = 111; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    // sort(arr, arr + n, greater<int>());
	sort(arr, arr + n);
    for (int i = 0; i < n; ++i) {
    	cout << arr[i] << ' ';
    }
    cout << '\n';
    int result = b_s(x, arr, 0, n - 1); 
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result; 
	return 0;
}
