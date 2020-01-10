#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

vector<int> g[N], cut_points;
int tin[N], fup[N], timer;
bool used[N];

void dfs(int v, int p = -1)
{
	used[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;
	for (int to: g[v]) {
		if (to == p) continue;
		if (!used[to]) fup[v] = min(fup[v], tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] >= tin[v] && p != -1)
				cut_points.push_back(v);
			children++;
		}
	}
	if (p == -1 && children > 1) 
		cut_points.push_back(v);
}

int main()
{
	// read graph
	for (int i = 1; i <= n; i++)
		if (!used[i])
			dfs(i);
}
