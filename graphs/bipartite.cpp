#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
int col[N];

bool dfs(int v, int cl)
{
	col[v] = 3 - cl;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (col[to] == col[v])
			return false;
		if (!col[to])
			if (!dfs(to, col[v]))
				return false;
	}
	return true;
}