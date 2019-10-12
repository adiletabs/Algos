#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> prefix_function(string s)
{
	int n = (int)s.length();
	vector<ll> pi (n);
	for (int i = 1; i < n; i++)
	{
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

// Knuth-Morris-Pratt algorithm
vector<int> KMP(string s, string t)
{
	int m = (int)t.length();
	vector<int> res;
	string l = t + '#' + s;
	vector<int> pi = prefix_function(l);
	for (int i = m + 1; i < l.length(); i++)
		if (pi[i] == m)
			res.push_back(i - 2 * m);
	return res;
}

// number of different substrings
ll unique_subs(string s)
{
	ll res = 0;
	string t = "";
	for (int i = 0; i < s.length(); i++)
	{
		t += s[i];
		reverse(t.begin(), t.end());
		vector<ll> pi = prefix_function(t);
		long long mx = 0;
		for (int j = 0; j < pi.size(); j++)
			mx = max(mx, pi[j]);
		res += (i + 1 - mx);
		reverse(t.begin(), t.end());
	}
	return res;
}

// compressed representation of the string
string compress(string s)
{
	vector<int> pi = prefix_function(s);
	int n = (int)s.length();
	int k = n - pi.back();
	return n % k ? s : s.substr(0, k);
}

// get the string from the given prefix function
string get(vector<int> pi)
{
	string ALPHA = "abcedfghijklmnopqrstuvwxyz", res = "";
	int ind = 0;
	for (int i = 0; i < pi.size(); i++)
	{
		if (pi[i] == 0)
			res += ALPHA[ind++];
		else
			res += res[pi[i] - 1]; 
	}
	return res;
}
