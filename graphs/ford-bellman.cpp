#include <bits/stdc++.h>
using namespace std;

struct Edge
{
	int u, v, w;
};

const int N = 100100, inf = 1e9;
int n, m, from;
vector<Edge> g;
int path[N];

void fb(int x)
{
	path[x] = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m; j++)
			if (path[g[j].u] < inf)
				path[g[j].v] = min(path[g[j].v], path[g[j].u] + g[j].w);
}

int main()
{
	for (int i = 0; i < N; i++)
		path[i] = inf;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		g.push_back({x, y, c});
	}
	cin >> from
	fb(from);
	for (int i = 1; i <= n; i++)
		cout << path[i] << ' ';
}
