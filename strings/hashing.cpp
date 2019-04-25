#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<long long> pows (N);

void get_pows()
{
	pows[0] = 1;
	for (int i = 1; i < N; i++)
		pows[i] = pows[i - 1] * 31;
}

long long hashof(string s)
{
	long long h = 0;
	for (int i = 0; i < s.length(); i++)
		h += (s[i] - 'a' + 1) * pows[i];
	return h;
}

vector<int> rabin_karp(string s, string t)
{
	int n = s.length(), m = t.length();
	vector<long long> h (n);
	for (int i = 0; i < n; i++)
	{
		h[i] = (s[i] - 'a' + 1) * pows[i];
		if (i) h[i] += h[i - 1];
	}
	long long hash_t = hashof(t);
	vector<int> res;
	for (int i = 0; i <= n - m; i++)
	{
		long long hash_s = h[i + m - 1];
		if (i) hash_s -= h[i - 1];
		if (hash_t * pows[i] == hash_s)
			res.push_back(i);
	}
	return res;
}
