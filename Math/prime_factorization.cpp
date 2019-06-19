/*----------------------------------------------------

Algorithm of prime factorization of number N

Constructs 'primes', which is map, 
where key is a prime number and value is it's factor

Time complexity - O(sqrt(N))

----------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

map<ll, int> primes;

void factorization(long long n)
{
	primes.clear();
	long long i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
		{
			primes[i]++;
			n /= i;
		}
		else i++;
	}
	primes[n]++;
}
