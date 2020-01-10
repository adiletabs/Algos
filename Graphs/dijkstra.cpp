#include <bits/stdc++.h>
using namespace std;

const int N = 2020, inf = INT_MAX;

vector<pair<int, int> > g[N];
int dist[N], par[N], n, m;
bool used[N];
vector<int> path;

void init()
{
	for (int i = 0; i < N; i++)
		dist[i] = inf;
}

void dijkstra(int s)
{
	init();
	dist[s] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) 
			if (!used[j] && (v == -1 || dist[j] < dist[v]))
				v = j;
		used[v] = true;
		for (pair<int, int> p: g[v]) {
			int to = p.first, len = p.second;
			if (dist[v] + len < dist[to]) {
				dist[to] = dist[v] + len;
				par[to] = v;
			}
		}
	}
}

void fast_dijkstra(int s)
{
	init();
	dist[s] = 0;
	set<pair<int, int> > best_vertices;
	best_vertices.insert(make_pair(dist[s], s));
	while (!best_vertices.empty()) {
		int v = best_vertices.begin()->second;
		best_vertices.erase(best_vertices.begin());
		for (pair<int, int> p: g[v]) {
			int to = p.first, len = p.second;
			if (dist[v] + len < dist[to]) {
				best_vertices.erase(make_pair(dist[to], to));
				dist[to] = dist[v] + len;
				par[to] = v;
				best_vertices.insert(make_pair(dist[to], to));
			}
		}
	}
}

void get_best_path(int start, int target)
{
	fast_dijkstra(start);
	for (int v = target; v != start; v = par[v])
		path.push_back(v);
	path.push_back(start);
	reverse(path.begin(), path.end());
}

int main()
{
	cin >> n >> m;
	while (m--) {
		int v, u, weight;
		g[v].push_back(make_pair(u, weight));
		g[u].push_back(make_pair(v, weight));
	}
	int start;
	cin >> start;
	fast_dijkstra(start);
	for (int i = 1; i <= n; i++)
		cout << dist[i] << ' ';
}
