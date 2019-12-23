/*--------------------------------------------------------------

Distance between points with coordinates (x1, y1) and (x2, y2)
or
length of vector (x1, y1), int this case x2 = 0, y2 = 0

--------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct point
{
	double x, y;
};

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double dist(point p1, point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
