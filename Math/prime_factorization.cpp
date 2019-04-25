#include <bits/stdc++.h>
using namespace std;

vector<long long> primes;

void factorization(long long n)
{
	primes.clear();
	long long i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
		{
			primes.push_back(i);
			n /= i;
		}
		else i++;
	}
	primes.push_back(n);
}
