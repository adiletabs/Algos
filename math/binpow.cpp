#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long binpow(long long a, long long n)
{
	long long res = 1;
	while (n)
	{
		if (n & 1)
		{
			res = (res * a) % mod;
			n--;
		}
		else
		{
			a = (a * a) % mod;
			n >>= 1;
		}
	}
	return res % mod;
}