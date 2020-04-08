/*--------------------------------

Binary exponentiation algorithm

Compute a^N modulo mod 
Time complexity - O(logN)

--------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll binpow(ll a, ll n)
{
	ll res = 1;
	while (n) {
		if (n & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		ll a, n;
		cin >> a >> n;
		cout << binpow(a, n) << '\n'; 
	}
}
