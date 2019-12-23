/*--------------------------------------

Ternary search algorithm

Finds the maximum/minimum value of 
any unimodal function

Here is an algorithm for finding the maximum
of a sample function f(x). Algorithm for
finding the minimum value is symmetrical

Time complexity - O(log(2/3)N)

--------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int f(int x) 
{
	return -x * x + 20;  
}

int ternary_search(int l, int t)
{
	while (r - l >= 3) {
		int d = (r - l) / 3;
		int m1 = l + d, m2 = r - d;
		if (f(m1) < f(m2)) l = m1;
		else if (f(m1) > f(m2)) r = m2;
		else {
			l = m1;
			r = m2;
		}
	}
	int res = f(l);
	for (int i = l + 1; i <= r; i++)
		res = max(res, f(i));
	return res;
}
