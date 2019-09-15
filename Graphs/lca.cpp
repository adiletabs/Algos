#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
int l, timer, time_in[N], time_out[N], up[N][20];    // up[i][j] - 2^j -th ancestor of i-th vertex

void dfs(int v, int p = 0)
{
	time_in[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= l; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to != p) dfs(to, v);
	}
	time_out[v] = ++timer;
}

bool is_ancestor(int v, int u)
{
	return (time_in[v] <= time_in[u] && time_out[v] >= time_out[u]);
}

int lca(int v, int u)
{
	if (is_ancestor(v, u)) return v;
	if (is_ancestor(u, v)) return u;
	for (int i = l; i >= 0; i--)
		if (up[v][i] && !is_ancestor(up[v][i], u))
			v = up[v][i];
	return up[v][0];
}

int main()
{
	int n, m;            // number of vertices and edges
	cin >> n >> m;
	while ((1 << l) <= n)  l++;
	// read graph
	dfs(root);
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << '\n';
	}
}
