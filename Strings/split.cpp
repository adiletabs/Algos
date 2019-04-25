#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s)   // separates string by spaces
{
	stringstream ss;
	ss << s;
	string token;
	vector<string> res;
	while (ss >> token)
		res.push_back(token.c_str());
	return res;
}

// separates string by some character
// e.g.separation by comma ',':
// input: "abc,def,ghi"
// resulting vector: "abc", "def", "ghi"

vector<string> split_by(string s, char c)
{
	stringstream ss;
	ss << s;
	string token;
	vector<string> res;
	while (getline(ss, token, c)) 
    	res.push_back(token);
}
