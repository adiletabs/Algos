#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> primes;

void resheto(ll n)
{
	if (n >= 2)
		primes.push_back(2);
	vector<char> prime (n + 1, true);
	for (ll i = 3; i <= n; i += 2)
	{
		if (prime[i])
		{
			primes.push_back(i);
			for (ll j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	}
}
