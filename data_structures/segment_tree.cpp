#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N];

struct segment_tree
{
	int t[4 * N], to[4 * N];
	segment_tree()
	{
		memset(t, 0, sizeof t);
		memset(t, 0, sizeof to);
	}
	void build(int v, int tl, int tr)
	{
		if (tl == tr)
			t[v] = a[tl];
		else
		{
			int tm = tl + tr >> 1;
			build(v + v, tl, tm);
			build(v + v + 1, tm + 1, tr);
			t[v] = t[v + v] + t[v + v + 1];
		}
	}
	int get(int v, int tl, int tr, int l, int r)
	{
		if (l > r) return 0;             // INT_MAX for ST_min, -1 for ST_max
		if (tl == l && tr == r) return t[v];
		t[v + v] += to[v];
		t[v + v + 1] += to[v];
		push(v);
		int tm = tl + tr >> 1;
		return get(v + v, tl, tm, l, min(tm, r)) + get(v + v + 1, tm + 1, tr, max(tm + 1, l), r);
	}
	void upd(int v, int tl, int tr, int pos, int x)
	{
		if (tl == tr) 
		{
			t[v] = x;
			a[tl] = x;
		}
		else
		{
			int tm = tl + tm >> 1;
			if (pos <= tm) 
				upd(v + v, tl, tm, pos, x);
			else 
				upd(v + v + 1, tm + 1, tr, pos, x);
			t[v] = t[v + v] + t[v + v + 1];
		}
	}
	void push(int v)
	{
		to[v + v] += to[v];
		to[v + v + 1] += to[v];
		to[v] = 0;
	}
	void add(int v, int tl, int tr, int l, int r, int val)
	{
		if (l > r) return;
		if (tl == l && tr == r)
		{
			t[v] += val;
			to[v] += val;
			return ;
		}
		t[v + v] += to[v];
		t[v + v + 1] += to[v];
		push(v);
		int tm = tl + tr >> 1;
		add(v + v, tl, tm, l, min(r, tm), val);
		add(v + v + 1, tm + 1, tr, max(tm + 1, l), r, val);
		t[v] = min(t[v + v], t[v + v + 1]);
	}
} T;