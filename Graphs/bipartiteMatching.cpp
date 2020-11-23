/*----------------------------------------------------------

Maximum bipartite matching
A matching in a bipartite graph is a set of the edges 
chosen in such a way that no two edges share an endpoint

Below is an implementation of finding a matching of the
maximum size in a bipartite graph with Kuhn's algorithm
Time complexity - O(N * M)

Related problems:

Minimum vertex cover - a minimum set of vertices such that 
every edge is incident of either of the vertices in that set
Size = size of maximum bipartite matching

Maximum independent set - a maximum set of vertices such 
that no pair of vertices in that set share a common edge
Size = N - size of maximum bipartite matching

Maximum clique - a subset of vertices such that every two 
distinct vertices in the clique are adjacent
Size = size of max indep. set in an inverted graph

----------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int col[N], used[N], matching[N], timer;
vector<int> g[N], part;

bool partition(int v, int cl) {
    col[v] = 3 - cl;
    if (col[v] == 1) part.push_back(v);
    for (int to: g[v]) {
        if (col[to] == col[v]) 
            return false;
        if (!col[to] && !partition(to, col[v]))
            return false;
    }
    return true;
}

bool dfsKuhn(int v) {
    if (used[v] == timer)
        return false;
    used[v] = timer;
    for (int to: g[v]) 
        if (matching[to] == -1) {
            matching[to] = v;
            return true;
        }   
    for (int to: g[v]) 
        if (dfsKuhn(matching[to])) {
            matching[to] = v;
            return true;
        } 
    return false;
}

int maxBipartiteMatching() {
    for (int v = 1; v <= n; v++)
        if (!col[v] && !partition(v)) {
            cout << "Graph is not bipartite\n";
            exit(0);
        }
    int res = 0;
    memset(matching, -1, sizeof matching);
    for (int v: part) {
        timer++;
        if (dfsKuhn(v)) res++;
    }
    return res;
}

int main() {
	// read graph
	cout << maxBipartiteMatching() << '\n';
    cout << "Edges of maximum bipartite matching:\n";
    for (int i = 1; i <= n; i++)
        if (matching[i] != -1)
            cout << i << ' ' << matching[i] << '\n';
}
