/*----------------------------------------------------

Computation C[n][k] modulo mod - the number of possible
combinations of k objects from a set of n objects

1st method: Precalc based on Pascal's triangle
Preprocessing - O(N^2) 
Access to any element - O(1)

2nd method: binary exponentiation with mod inverse
Factorials calculation - O(N)
Getting C[n][k] - O(logN)

----------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int N = 5000;

ll C[N][N], f[N];

void pascal_precalc()            
{                                   
	for (int i = 0; i < N; i++)    
	{                              
		C[i][0] = 1, C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
}

void factorial_precalc()
{
	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = f[i - 1] * 1LL * i; 
}

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

ll c(int n, int k)       
{                        
	ll res = f[n];
	res = (res * binpow(f[k], mod - 2)) % mod;
	res = (res * binpow(f[n - k], mod - 2)) % mod;
	return res;
}
