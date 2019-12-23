/*----------------------------------------------------------------------

Given: segment with ends at points (x1, y1) and (x2, y2)
Find: number of points with integer coordinates belonging this segment

----------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int get(int x1, int y1, int x2, int y2)
{
	return __gcd(abs(x1 - x2), abs(y1 - y2)) + 1;
}
