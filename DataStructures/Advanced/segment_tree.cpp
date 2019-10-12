#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N], n, q;

struct segment_tree
{
	int t[N << 2], to[N << 2];
	segment_tree() {
		memset(t, 0, sizeof t);
		memset(t, 0, sizeof to);
	}
	void build(int v = 1, int tl = 1, int tr = n)
	{
		if (tl == tr)
			t[v] = a[tl];
		else {
			int tm = tl + tr >> 1;
			build(v + v, tl, tm);
			build(v + v + 1, tm + 1, tr);
			t[v] = t[v + v] + t[v + v + 1];
		}
	}
	int get(int l, int r, int v = 1, int tl = 1, int tr = n)
	{
		if (l > r) return 0;             // INT_MAX for ST_min, -1 for ST_max
		if (tl == l && tr == r) return t[v];
		t[v + v] += to[v];
		t[v + v + 1] += to[v];
		push(v);
		int tm = tl + tr >> 1;
		return get(l, min(tm, r), v + v, tl, tm) + get(max(tm + 1, l), r, v + v + 1, tm + 1, tr);
	}
	void upd(int pos, int x, int v = 1, int tl = 1, int tr = n)
	{
		if (tl == tr) {
			t[v] = x;
			a[pos] = x;
		} else {
			int tm = tl + tr >> 1;
			if (pos <= tm) 
				upd(pos, x, v + v, tl, tm);
			else 
				upd(pos, x, v + v + 1, tm + 1, tr);
			t[v] = t[v + v] + t[v + v + 1];
		}
	}
	void push(int v)
	{
		to[v + v] += to[v];
		to[v + v + 1] += to[v];
		to[v] = 0;
	}
	void add(int l, int r, int val, int v = 1, int tl = 1, int tr = n)
	{
		if (l > r) return;
		if (tl == l && tr == r) {
			t[v] += val;
			to[v] += val;
			return;
		}
		t[v + v] += to[v];
		t[v + v + 1] += to[v];
		push(v);
		int tm = tl + tr >> 1;
		add(l, min(r, tm), val, v + v, tl, tm);
		add(max(tm + 1, l), r, val, v + v + 1, tm + 1, tr);
		t[v] = t[v + v] + t[v + v + 1];
	}
} T;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	T.build();
	cin >> q;
	while (q--) {
		string com;
		cin >> com;
		if (com == "get") {
			int l, r;
			cin >> l >> r;
			cout << T.get(l, r) << '\n';
		} else if (com == "upd") {
			int pos, x;
			cin >> pos >> x;
			T.upd(pos, x);
		} else if (com == "add") {
			int l, r, x;
			cin >> l >> r >> x;
			T.add(l, r, x);
		}
		for (int i = 1; i <= n; i++)
			cout << a[i] << ' ';
		cout << endl;
	}
}
