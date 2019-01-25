#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
int tin[N], fup[N], timer;
bool used[N];

void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (int i = 0; i < g[v].size(); i++) 
	{
		int to = g[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min(fup[v], tin[to]);
		else 
		{
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v])
				// edge [v, to] is a bridge, do some action
		}
	}
}

int main()
{
	// reading graph
	for (int i = 1; i <= n; i++)
		if (!used[i])
			dfs(i);
}