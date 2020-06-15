/*--------------------------------------

Classical binary search algorithm

Checks wether number x is in the array
Requires array to be sorted

Time complexity - O(logN)

--------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

int a[N];

bool binary_search(int l, int r, int x) {
	while (l <= r) {
		int mid = l + r >> 1;
		if (a[mid] == x)
			return true;
		else if (a[mid] < x)
			l = mid + 1;
		else if (a[mid] > x)
			r = mid - 1;
	}
	return false;
}
