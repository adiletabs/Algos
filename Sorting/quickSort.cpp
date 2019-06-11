#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
int a[N];

void qksort(int l, int r)
{
	int piv = a[(l + r) / 2];
	int i = l, j = r;
	while (i <= j)
	{
		while (i <= r && a[i] < piv)
			i++;
		while (j >= l && a[j] > piv)
			j--;
		if (i >= j)
			break;
		swap(a[i++], a[j--]);
	}
  	if (l < r)
  	{
  		qksort(l, j);
  		qksort(j + 1, r);
    }
} 
