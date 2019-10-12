#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int start, finish, col[N], path[N];
vector<int> g[N];

bool dfs(int v)                // directed graph
{
	col[v] = 1;
	for (int to: g[v]) {
		if (col[to] == 1) {
			start = to;
			finish = v;
			return true;
		}
		else if (!col[to]) {
			path[to] = v;
			if (dfs(to))
				return true;
		}
	}
	col[v] = 2;
	return false;
}

bool dfs(int v, int from)      // undirected graph
{
	col[v] = 1;
	for (int to: g[v]) {
		if (col[to] == 1 && to != from) {
			start = to;
			finish = v;
			return true; 
		} else if (!col[to]) {
			path[to] = v;
			if (dfs(to, v))
				return true;
		}
	}
	col[v] = 2;
	return false;
}

void print()
{
	cout << "Cycle found!\n";
	vector<int> cycle;
	for (int v = finish; v != start; v = path[v])
		cycle.push_back(v);
	cycle.push_back(start);
	reverse(cycle.begin(), cycle.end());
	for (int i: cycle) cout << i << ' ';
	exit(0);
}

int main()
{
	// read graph
	for (int i = 1; i <= N; i++)
		if (!col[i] && dfs(i, -1))
			print();
	cout << "Acyclic";
}
