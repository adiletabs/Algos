#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 1e18;
const int N = 200100;

int n;
ll a[N], mn[N << 2], t[N << 2], memo[N << 2];

void pull(int v) {
	t[v] = t[v << 1] + t[v << 1 | 1];
	mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
}

void build(int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) t[v] = mn[v] = a[tl];
	else {
		int tm = tl + tr >> 1;
		build(v << 1, tl, tm);
		build(v << 1 | 1, tm + 1, tr);
		pull(v);
	}
}

void push(int v, ll tl, ll tr) {
	ll tm = tl + tr >> 1;
	t[v << 1] += memo[v] * (tm - tl + 1);
	t[v << 1 | 1] += memo[v] * (tr - tm);
	mn[v << 1] += memo[v];
	mn[v << 1 | 1] += memo[v];
	memo[v << 1] += memo[v];
	memo[v << 1 | 1] += memo[v];
	memo[v] = 0;
}

ll getSum(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (tl > r || tr < l) return 0;       
	if (tl >= l && tr <= r) return t[v];
	push(v, tl, tr);
	int tm = tl + tr >> 1;
	ll leftSum = getSum(l, r, v << 1, tl, tm);
	ll rightSum = getSum(l, r, v << 1 | 1, tm + 1, tr);
	return leftSum + rightSum;
}

ll getMin(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (tl > r || tr < l) return inf;       
	if (tl >= l && tr <= r) return mn[v];
	push(v, tl, tr);
	int tm = tl + tr >> 1;
	ll leftMin = getMin(l, r, v << 1, tl, tm);
	ll rightMin = getMin(l, r, v << 1 | 1, tm + 1, tr);
	return min(leftMin, rightMin);
}

void add(int l, int r, ll val, int v = 1, int tl = 1, int tr = n) {
	if (tl > r || tr < l) return;
	if (tl >= l && tr <= r) {
		t[v] += val * (tr - tl + 1);
		mn[v] += val;
		memo[v] += val;
		return;
	}
	push(v, tl, tr);
	int tm = tl + tr >> 1;
	add(l, r, val, v << 1, tl, tm);
	add(l, r, val, v << 1 | 1, tm + 1, tr);
	pull(v);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build();
	int q; cin >> q;
	while (q--) {
		string com;
		cin >> com;
		if (com == "sum") {
			int l, r;
			cin >> l >> r;
			cout << getSum(l, r) << '\n';
		} else if (com == "min") {
			int l, r;
			cin >> l >> r;
			cout << getMin(l, r) << '\n';
		} else if (com == "add") {
			int l, r;
			ll val;
			cin >> l >> r >> val;
			add(l, r, val);
		}
	}
}
