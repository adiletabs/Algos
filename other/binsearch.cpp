#include <bits/stdc++.h>
using namespace std;

int a[N];
//sort array

bool binsearch(int l, int r, int x)
{
	if (l > r)
		return false;
	int mid = l + r >> 1;
	if (a[mid] == x)
		return true;
	else if (a[mid] < x)
		binsearch(mid + 1, r, x);
	else if (a[mid] > x)
		binsearch(l, mid - 1, x);
}

bool binsearch(int l, int r, int x)
{
	while (l <= r)
	{
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
