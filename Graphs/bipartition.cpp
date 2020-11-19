#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
int col[N];

bool dfs(int v, int cl) {
	col[v] = 3 - cl;
	for (int to: g[v]) {
		if (col[to] == col[v])
			return false;
		if (!col[to] && !dfs(to, col[v]))
			return false;
	}
	return true;
}

int main() {
	// read graph
	for (int i = 1; i <= n; i++)
		if (!col[i] && !dfs(i))
			return cout << "Not bipartite", 0;
	cout << "Bipartite";
}
