/*--------------------------------------------------------------

Shanks' algorithm for computing the discrete logarithm
More known as 'baby-step giant-step' algorithm

Finds any solution of a^x = b (mod m), where a, b, m are given
Time complexity - O(sqrt(m))

--------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

ll binpow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}

ll discr_log(ll a, ll b) {
	ll n = (ll)sqrt(mod * 1.0) + 1;
	ll an = binpow(a, n);
	map<ll, ll> vals;
	for (ll i = 1, cur = an; i <= n; i++) {
		if (!vals.count(cur))
			vals[cur] = i;
		cur = (cur * an) % mod; 
	}
	for (ll i = 0, cur = b; i <= n; i++) {
		if (vals.count(cur)) {
			ll res = vals[cur] * n - i;
			if (res < mod)
				return res;
		}
		cur = (cur * a) % mod;
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll a, b;
		cin >> a >> b;
		cout << discr_log(a, b) << '\n';
	}
}
