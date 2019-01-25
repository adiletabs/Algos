#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];

void bfs(int v)
{
	bool used[N];
	used[v] = true;
	queue<int> q;
	q.push(v);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < g[u].size(); i++)
		{
			int to = g[u][i];
			if (!used[to])
			{
				used[to] = true;
				q.push(to);
			} 
		}
	}
}