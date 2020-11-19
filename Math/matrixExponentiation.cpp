/*-----------------------------------------

Computation of N-th Fibonacci number modulo mod 
using matrix exponentiation technique

Time complexity - O(logN)

-----------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Sz = 2;
const int mod = 1e9 + 7;

struct Matrix {
	ll mat[Sz][Sz];
};

Matrix mult(Matrix a, Matrix b) {
	Matrix res;
	for (int i = 0; i < Sz; i++)
		for (int j = 0; j < Sz; j++) {
			res.mat[i][j] = 0;
			for (int k = 0; k < Sz; k++) {
				ll plus = (a.mat[i][k] * b.mat[k][j]) % mod;
				res.mat[i][j] += plus;
				res.mat[i][j] %= mod;
			}
		}
	return res;
}

Matrix unit() {
	Matrix res;
	for (int i = 0; i < Sz; i++)
		for (int j = 0; j < Sz; j++)
			res.mat[i][j] = (i == j);
	return res;
}

Matrix binpow(Matrix base, ll n) {
	Matrix res = unit();
	while (n) {
		if (n & 1) res = mult(res, base);
		base = mult(base, base);
		n >>= 1;
	}
	return res;
}

ll get_fibonacci(ll n) {
	Matrix P;
	for (int i = 0; i < Sz; i++)
		for (int j = 0; j < Sz; j++)
			P.mat[i][j] = (i + j > 0);
	P = binpow(P, n);
	return P.mat[1][0];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll n;
		cin >> n;
		cout << get_fibonacci(n) << '\n';
	}
}
