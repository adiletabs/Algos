#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N], order;
bool used[N];

void dfs(int v)
{
	used[v] = true;
	for (int to: g[v]) {
		if (!used[to])
			dfs(to);
	}
	order.push_back(v);
}

void top_sort()
{
	for (int i = 1; i <= n; i++)
		if (!used[i])
			dfs(i);
	reverse(order.begin(), order.end());
}

int main()
{
	// reading graph
	// check for cyclicity
	// if graph is cyclic, topsort is impossible
	top_sort();
}
