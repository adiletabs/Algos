#include <bits/stdc++.h>
using namespace std;

// given: coordinates of two points (x1, y1) and (x2, y2)
// find: normal equality of the line crossing these points
// A * x + B * y + C = 0

struct point
{
	double x, y;
};

double A, B, C;

void get(double x1, double y1, double x2, double y2)
{
	A = y1 - y2;
	B = x2 - x1;
	C = -A * x1 - B * y1;
}

void get(point p1, point p2)
{
	A = p1.y - p2.y;
	B = p2.x - p1.x;
	C = -A * p1.x - B * p1.y;
}