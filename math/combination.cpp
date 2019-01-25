#include <bits/stdc++.h>
using namespace std;

const int N = 5000, mod = 1e9 + 7;
long long C[N][N];

void get_combinations()         // precalc with Pascal's triangle
{                               // time complexity - N^2    
	for (int i = 0; i < N; i++)
	{
		C[i][0] = 1, C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
}

long long c(int n, int k)       // for small values of n
{                               // unable to calculate combinations modulo m
	long long res = 1;
	for (int i = n - k + 1; i <= n; i++)
		res *= i;
	for (int i = 2; i <= k; i++)
		res /= i;
}