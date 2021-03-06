/*------------------------------------------

Newton's algorithm for finding square root
Also known as Babylonian algorithm

------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

double sqroot(double n) {
	if (n < 0) {
		"Impossible";
		exit(0);
	}
	double s = n;
	while (fabs(s - n / s) > eps)
		s = (s + n / s) / 2;
	return s;
}
