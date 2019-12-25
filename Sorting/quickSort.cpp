/*----------------------------------

Quick-sort algorithm

Time complexity - O(NlogN)
Additional space complexity - O(1)

----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
int a[N];

void quickSort(int l, int r)
{
	int piv = a[(l + r) / 2];
	int i = l, j = r;
	while (i <= j) {
		while (i <= r && a[i] < piv)
			i++;
		while (j >= l && a[j] > piv)
			j--;
		if (i >= j)
			break;
		swap(a[i++], a[j--]);
	}
  	if (l < r) {
  		quickSort(l, j);
  		quickSort(j + 1, r);
    }
} 

int main()
{   
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quickSort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}
