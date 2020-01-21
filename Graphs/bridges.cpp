#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
int tin[N], fup[N], timer;
bool used[N];
vector<pair<int, int> > bridges;

void dfs(int v, int p = -1) 
{
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (int to: g[v]) {
		if (to == p)  continue;
		if (used[to]) fup[v] = min(fup[v], tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v])
				bridges.push_back(make_pair(v, to));
		}
	}
}

int main()
{
	// read graph
	for (int i = 1; i <= n; i++)
		if (!used[i])
			dfs(i);
}
