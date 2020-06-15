/*-------------------------------------------------------

Given: coordinates of two points (x1, y1) and (x2, y2)
Find: normal equality of the line crossing these points
A * x + B * y + C = 0

-------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
};

double A, B, C;

void get_coefficients(double x1, double y1, double x2, double y2) {
	A = y1 - y2;
	B = x2 - x1;
	C = -A * x1 - B * y1;
}

void get_coefficients(point p1, point p2) {
	A = p1.y - p2.y;
	B = p2.x - p1.x;
	C = -A * p1.x - B * p1.y;
}
