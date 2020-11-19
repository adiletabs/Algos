#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 1e18;
const int N = 200100;

ll n, a[N], mx[N << 2], t[N << 2], memo[N << 2];

void pull(int v) {
	t[v] = t[v << 1] + t[v << 1 | 1];
	mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
}

void build(int v = 1, ll tl = 1, ll tr = n) {
	if (tl == tr) t[v] = mx[v] = a[tl];
	else {
		ll tm = tl + tr >> 1;
		build(v << 1, tl, tm);
		build(v << 1 | 1, tm + 1, tr);
		pull(v);
	}
}

void update(ll pos, ll val, int v = 1, ll tl = 1, ll tr = n) {
	if (tl == tr) t[v] = mx[v] = val;
	else {
		ll tm = tl + tr >> 1;
		if (pos <= tm) update(pos, val, v << 1, tl, tm);
		else update(pos, val, v << 1 | 1, tm + 1, tr);
		pull(v);
	}
}

void push(int v, ll tl, ll tr) {
	if (!memo[v]) return;
	mx[v << 1] = memo[v << 1] = memo[v];
	mx[v << 1 | 1] = memo[v << 1 | 1] = memo[v];
	ll tm = tl + tr >> 1;
	t[v << 1] = (tm - tl + 1) * memo[v];
	t[v << 1 | 1] = (tr - tm) * memo[v];
	memo[v] = 0;
}

ll getSum(ll l, ll r, int v = 1, ll tl = 1, ll tr = n) {
	if (tl > r || tr < l) return 0;       
	if (tl >= l && tr <= r) return t[v];
	push(v, tl, tr);
	ll tm = tl + tr >> 1;
	ll leftSum = getSum(l, r, v << 1, tl, tm);
	ll rightSum = getSum(l, r, v << 1 | 1, tm + 1, tr);
	return leftSum + rightSum;
}

ll getMax(ll l, ll r, int v = 1, ll tl = 1, ll tr = n) {
	if (tl > r || tr < l) return -inf;       
	if (tl >= l && tr <= r) return mx[v];
	push(v, tl, tr);
	ll tm = tl + tr >> 1;
	ll leftMax = getMax(l, r, v << 1, tl, tm);
	ll rightMax = getMax(l, r, v << 1 | 1, tm + 1, tr);
	return max(leftMax, rightMax);
}

void assign(ll l, ll r, ll val, int v = 1, ll tl = 1, ll tr = n) {
	if (tl > r || tr < l) return;
	if (tl >= l && tr <= r) {
		t[v] = (tr - tl + 1) * val;
		mx[v] = val;
		memo[v] = val;
		return;
	}
	push(v, tl, tr);
	ll tm = tl + tr >> 1;
	assign(l, r, val, v << 1, tl, tm);
	assign(l, r, val, v << 1 | 1, tm + 1, tr);
	pull(v);
}

int main() {
	cin >> n;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	build();
	int q; cin >> q;
	while (q--) {
		string com;
		cin >> com;
		if (com == "sum") {
			ll l, r;
			cin >> l >> r;
			cout << getSum(l, r) << '\n';
		} else if (com == "max") {
			ll l, r;
			cin >> l >> r;
			cout << getMax(l, r) << '\n';
		} else if (com == "update") {
			ll pos, val;
			cin >> pos >> val;
			update(pos, val);
		} else if (com == "assign") {
			ll l, r, val;
			cin >> l >> r >> val;
			assign(l, r, val);
		}
	}
}
