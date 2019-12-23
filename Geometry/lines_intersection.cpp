/*----------------------------------------------

Given: normal equations of two lines in format
A * x + B * y + C = 0
Find: point of intersection of these lines

----------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct point
{
	double x, y;
};

point intersection(double a1, double b1, double c1, double a2, double b2, double c2)
{
	double x0, y0;
	if (a1 == 0 && b2 == 0)
	{
		x0 = -c2 / a2;
		y0 = -c1 / b1;
	}
	else if (b1 == 0 && a2 == 0)
	{
		x0 = -c1 / a1;
		y0 = -c2 / b2;
	}
	else if (a1 == 0)
	{
		y0 = -c1 / b1;
		x0 = (-b2 * y0 - c2) / a2;
	}
	else if (a2 == 0)
	{
		y0 = -c2 / b2;
		x0 = (-b1 * y0 - c1) / a1;
	}
	else if (b1 == 0)
	{
		x0 = -c1 / a1;
		y0 = (-a2 * x0 - c2) / b2;
	}
	else if (b2 == 0)
	{
		x0 = -c2 / a2;
		y0 = (-a1 * x0 - c1) / b1;
	}
	else
	{
		y0 = (c2 * a1 - c1 * a2) / (b1 * a2 - b2 * a1);
		x0 = (-c1 - b1 * y0) / a1;
	}
	return {x0, y0};
}
