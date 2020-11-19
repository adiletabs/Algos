#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200100;

int n;
ll a[N], t[N];

void add(int pos, ll val) {
	for (; pos <= n; pos |= pos + 1)
		t[pos] += val;
}

ll get(int r) {
	ll res = 0;
	for (; r >= 1; r = (r & (r + 1)) - 1)
		res += t[r];
	return res;
}

ll get(int l, int r) {
	return get(r) - get(l - 1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		add(i, a[i]);
	}
	int T;
	cin >> T;
	while (T--) {
		string com;
		cin >> com;
		if (com == "sum") {
			int l, r;
			cin >> l >> r;
			cout << get(l, r) << '\n';
		} else if (com == "add") {
			int pos;
			ll val;
			cin >> pos >> val;
			add(pos, val);
		}
	}
}
