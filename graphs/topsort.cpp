#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N], ans;
bool used[N];

// check for acyclicity

void dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
	ans.push_back(v);
}

void top_sort()
{
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i);
	reverse(ans.begin(), ans.end());
}
