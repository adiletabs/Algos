#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
const int LOG = 17; 

int n, a[N]; 
int logs[N], table[N][LOG];

void calc()
{
	for (int i = 2; i < N; i++)
		logs[i] = logs[i >> 1] + 1;
	for (int i = 0; i < n; i++)
		table[i][0] = a[i];
	for (int i = 1; i <= logs[n]; i++)
	{
		int len = 1 << i;
		for (int j = 0; j + len <= n; j++)
			table[j][i] = min(table[j][i - 1], table[j + (len >> 1)][i - 1]);
	}
}

int get(int l, int r)
{
	int p = logs[r - l + 1];
	int len = 1 << p;
	return min(table[l][p], table[r - len + 1][p]);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	calc();
	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << get(l, r) << '\n';
	}
}
