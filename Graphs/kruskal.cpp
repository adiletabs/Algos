#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<pair<int, pair<int, int > > > g;
vector<pair<int, int > > mst_edges;
int par[N], weight;

int get_set(int v)
{
	return v == par[v] ? v : par[v] = get_set(par[v]);
}

void merge(int a, int b)
{
	a = get_set(a);
	b = get_set(b);
	if (a != b)
		par[b] = a;
}

void MST()
{
	sort(g.begin(), g.end());
	for (int i = 0; i < g.size(); i++) {
		int a = g[i].second.first, b = g[i].second.second;
		if (get_set(a) != get_set(b)) {
			weight += g[i].first;
			mst_edges.push_back(make_pair(a, b));
			merge(a, b);
		}
	}
}

int main()
{
	// read graph
	MST();
	printf("MST weight: %d\n", weight);
	for (pair<int, int> p: mst_edges)
		cout << p.first << ' ' << p.second << '\n';
}
