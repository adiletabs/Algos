#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
bool used[N];
int time_in[N], time_out[N], timer;

void dfs(int v) {
	used[v] = true;
	time_in[v] = ++timer;
	for (int to: g[v]) 
		if (!used[to])
			dfs(to);
	time_out[v] = ++timer;
}
