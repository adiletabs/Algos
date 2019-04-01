#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int par[N];

void make_set(int v)
{
	par[v] = v;
}

int get_set(int v)
{
	return v == par[v] ? v : par[v] = get_set(par[v]);
}

void merge(int a, int b)
{
	a = get_set(a);
	b = get_set(b);
	if (a != b)
		par[b] = a;
}
