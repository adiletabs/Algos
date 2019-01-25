#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) 
{
	int n = (int)s.length();
	vector<int> z (n);
	for (int i = 1, l = 0, r = 0; i < n; i++) 
	{
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
			l = i,  r = i + z[i] - 1;
	}
	return z;
}

// get the string from the given z-function
string get(vector<int> z)
{
	string ALPHA = "abcedfghijklmnopqrstuvwxyz", res = "";
	int len = 0, ind = 0, j;
	z[0] = 0;
	for (int i = 0; i < z.size(); i++)
	{
		if (z[i] == 0 && len == 0)
		{
			if (ind < 52)
				res += ALPHA[ind++];
			else
				res += ALPHA[ind - 1];
		}
		if (z[i] > len)
		{
			len = z[i];
			j = 0;
		}
		if (len > 0)
		{
			res += res[j];
			j++;
			len--;
		}
	}
	return res;
}