#include <bits/stdc++.h>
using namespace std;

// Manacher's algorithm - find all subpalindromes of a string

vector<int> odds(string s)    // number of palindromes of odd 
{                             // length with center at i-th symbol
	int n = (int)s.length();
	vector<int> d (n);
	int l = 0, r = -1;
	for (int i = 0; i < n; i++) 
	{
		int k = (i > r ? 1 : min(d[l + r - i], r - i));
		while (i + k < n && i - k >= 0 && s[i - k] == s[i + k]) k++;
		d[i] = k;
		if (i + k - 1 > r)
			l = i - k + 1, r = i + k - 1;
	}
	return d;
}

vector<int> evens(string s)  // number of palindromes of even
{                            // length with center at (i-0.5)-th symbol
	int n = (int)s.length();
	vector<int> d (n);
	int l = 0, r = -1;
	for (int i = 0; i < n; i++) 
	{
		int k = (i > r ? 0 : min(d[l + r - i + 1], r - i + 1));
		while (i + k < n && i - k - 1 >= 0 && s[i - k - 1] == s[i + k]) k++;
		d[i] = k;
		if (i + k - 1 > r)
			l = i - k, r = i + k - 1;
	}
	return d;
}

vector<string> get_palindromes(string s)
{
	vector<int> o = odds(s);
	vector<int> e = evens(s);
	vector<string> res;
	for (int i = 0; i < o.size(); i++)
	{
		string t = "";
		int k = 0;
		while (k != o[i])
		{
			t += s[i + k];
			if (k) t = s[i - k] + t;
			res.push_back(t);
			k++;
		}
	}
	for (int i = 0; i < e.size(); i++)
	{
		string t = "";
		int k = 0;
		while (k != e[i])
		{
			if (!k) t = t + s[i] + s[i];
			else t = s[i + k] + t + s[i + k];
			res.push_back(t);
			k++;
		}
	}
	return res;
}

int main()
{
	string s;
	cin >> s;
	vector<string> p = get_palindromes(s);
	for (string t : p)
		cout << t << '\n';
}