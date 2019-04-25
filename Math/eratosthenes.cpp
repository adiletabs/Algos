#include <bits/stdc++.h>
using namespace std;

vector<long long> primes;

void resheto(long long n)
{
	if (n >= 2)
		primes.push_back(2);
	vector<char> prime (n + 1, true);
	for (long long i = 3; i <= n; i += 2)
	{
		if (prime[i])
		{
			primes.push_back(i);
			for (long long j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	}
}
