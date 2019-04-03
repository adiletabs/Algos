#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int n, m;
vector<int> g[N], gr[N], order, comp;
vector<vector<int> > strong_comps;
bool used[N];

void dfs1(int v)
{
	used[v] = true;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to])
			dfs1(to);
	}
	order.push_back(v);
}

void top_sort()
{
	for (int i = 1; i <= n; i++)
		if (!used[i])
			dfs1(i);
	reverse(order.begin(), order.end());
}

void dfs2(int v)
{
	used[v] = true;
	comp.push_back(v);
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to])
			dfs2(to);
	}
}

void go()
{
	top_sort();
	memset(used, 0, sizeof used);
	for (int i = 0; i < n; i++)
	{
		int v = order[i];
		if (!used[v])
		{
			comp.clear();
			dfs2(v);
			strong_comps.push_back(comp);
		}
	}
}

int main()
{
	// reading gpaph
	go();
}
