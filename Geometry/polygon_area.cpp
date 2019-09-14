#include <bits/stdc++.h>
using namespace std;

struct point
{
	double x, y;
};

double area(vector<point> v)
{
	double res = 0;
	for (int i = 0; i < v.size(); i++) {
		point p1 = i ? v[i - 1] : v.back(), p2 = v[i];
		res += (p1.x - p2.x) * (p1.y + p2.y);
	}
	return fabs(res) / 2;
}
