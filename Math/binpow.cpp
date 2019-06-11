#include <bits/stdc++.h>
using namespace std;

// compute a^n modulo mod in O(logn)

const int mod = 1e9 + 7;

long long binpow(long long a, long long n)
{
	long long res = 1;
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
	long long a, n;
	cin >> a >> n;
	cout << binpow(a, n); 
}
