/*----------------------------------------------

Sieve of Eratosthenes algorithm
for finding all prime numbers in range [2, n]

Time complexity - O(NloglogN)

----------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> primes;

void sieve(ll n)
{
	if (n >= 2)
		primes.push_back(2);
	vector<bool> prime (n + 1, true);
	for (ll i = 3; i <= n; i += 2) {
		if (prime[i]) {
			primes.push_back(i);
			for (ll j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	}
}
