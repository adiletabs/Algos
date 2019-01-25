#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

double sqroot(double n)
{
	if (n < 0)
		return -1;
	double s = n;
	while (fabs(s - n / s) > eps)
		s = (s + n / s) / 2;
	return s;
}