#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
int n, tin[N], up[N], timer;
bool used[N];
vector<pair<int, int> > bridges;

void dfs(int v, int p = -1) {
	used[v] = true;
	tin[v] = up[v] = timer++;
	for (int to: g[v]) {
		if (to == p)  continue;
		if (used[to]) up[v] = min(up[v], tin[to]);
		else {
			dfs(to, v);
			up[v] = min(up[v], up[to]);
			if (up[to] > tin[v])
				bridges.push_back(make_pair(v, to));
		}
	}
}

int main() {
	// read graph
	for (int i = 1; i <= n; i++)
		if (!used[i])
			dfs(i);
}
