#include <bits/stdc++.h>
using namespace std;

struct Node {
	int sum, min, add;
};

const int N = 100100, inf = 2e9;
int a[N], n, q;
Node t[N << 2];

void build(int v = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		t[v].sum = t[v].min = a[tl];
	else {
		int tm = tl + tr >> 1;
		build(v + v, tl, tm);
		build(v + v + 1, tm + 1, tr);
		t[v].sum = t[v + v].sum + t[v + v + 1].sum;
		t[v].min = min(t[v + v].min, t[v + v + 1].min);
	}
}

void update(int pos, int val, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v].sum = t[v].min = val;
		a[pos] = val;
	} else {
		int tm = tl + tr >> 1;
		if (pos <= tm) 
			update(pos, val, v + v, tl, tm);
		else 
			update(pos, val, v + v + 1, tm + 1, tr);
		t[v].sum = t[v + v].sum + t[v + v + 1].sum;
		t[v].min = min(t[v + v].min, t[v + v + 1].min);
	}
}

void push(int v) {
	t[v + v].sum += t[v].add;
	t[v + v + 1].sum += t[v].add;
	t[v + v].add += t[v].add;
	t[v + v + 1].add += t[v].add;
	t[v].add = 0;
}

int getSum(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r) return 0;            
	if (tl == l && tr == r) return t[v].sum;
	push(v);
	int tm = tl + tr >> 1;
	return getSum(l, min(tm, r), v + v, tl, tm) + getSum(max(tm + 1, l), r, v + v + 1, tm + 1, tr);
}

int getMin(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r) return inf;            
	if (tl == l && tr == r) return t[v].min;
	push(v);
	int tm = tl + tr >> 1;
	return min(getMin(l, min(tm, r), v + v, tl, tm), getMin(max(tm + 1, l), r, v + v + 1, tm + 1, tr));
}

void add(int l, int r, int val, int v = 1, int tl = 1, int tr = n) {
	if (l > r) return;
	if (tl == l && tr == r) {
		t[v].sum += val;
		t[v].add += val;
		return;
	}
	push(v);
	int tm = tl + tr >> 1;
	add(l, min(r, tm), val, v + v, tl, tm);
	add(max(tm + 1, l), r, val, v + v + 1, tm + 1, tr);
	t[v].sum = t[v + v].sum + t[v + v + 1].sum;
	t[v].min = min(t[v + v].min, t[v + v + 1].min);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build();
	cin >> q;
	while (q--) {
		string command;
		cin >> command;
		if (command == "sum") {
			int l, r;
			cin >> l >> r;
			cout << getSum(l, r) << '\n';
		} else if (command == "min") {
			int l, r;
			cin >> l >> r;
			cout << getMin(l, r) << '\n';
		} else if (command == "update") {
			int pos, val;
			cin >> pos >> val;
			update(pos, val);
		} else if (command == "add") {
			int l, r, val;
			cin >> l >> r >> val;
			add(l, r, val);
		}
	}
}
