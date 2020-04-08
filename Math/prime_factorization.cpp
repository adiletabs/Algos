/*----------------------------------------------------

Algorithm of prime factorization of number N

Constructs 'primes', which is map, 
where key is a prime number and value is it's factor

Time complexity - O(sqrt(N))

----------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<ll, int> primes;

void fact(ll n)
{
	primes.clear();
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			primes[i]++;
			n /= i;
		}
	}
	if (n > 1) primes[n]++;
}
