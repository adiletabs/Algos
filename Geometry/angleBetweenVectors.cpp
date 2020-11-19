/*--------------------------------------------------------------

Given: vectors v1 and v2 with coordinates (x1, y1) and (x2, y2)
Find: angle in radians between these vectors

Based on the scalar product of vectors:
|v1| * |v2| * cos(angle) = x1 * x2 + y1 * y2

--------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

double angle(double x1, double y1, double x2, double y2) {
	double l1 = sqrt(x1 * x1 + y1 * y1), l2 = sqrt(x2 * x2 + y2 * y2);
	double a = (x1 * x2 + y1 * y2) / (l1 * l2);
	return acos(a);
}
