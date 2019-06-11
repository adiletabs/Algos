#include <bits/stdc++.h>
using namespace std;

// compute a^n modulo mod in O(logn)

typedef long long ll;

const int mod = 1e9 + 7;

ll binpow(ll a, ll n)
{
	ll res = 1;
	while (n) 
	{
		if (n & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}

int main()
{
	ll a, n;
	cin >> a >> n;
	cout << binpow(a, n); 
}
