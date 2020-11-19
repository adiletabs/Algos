#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100100;

int n;
ll a[N], f[N];

void update(int pos, ll x) {
	for (; pos <= n; pos |= (pos + 1))
		f[pos] += x;
}

ll get(int r) {
	ll res = 0;
	for (; r >= 1; r = (r & (r + 1)) - 1)
		res += f[r];
	return res;
}

ll get(int l, int r) {
	return get(r) - get(l - 1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		upd(i, a[i]);
	}
	int T;
	cin >> T;
	while (T--) {
		string type;
		cin >> type;
		if (type == "get") {
			int l, r;
			cin >> l >> r;
			cout << get(l, r) << '\n';
		} else if (type == "upd") {
			int pos;
			ll x;
			cin >> pos >> x;
			upd(pos, x);
			a[pos] += x;
		}
	}
}
