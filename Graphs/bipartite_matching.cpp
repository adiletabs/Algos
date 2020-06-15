#include <bits/stdc++.h>
using namespace std;

const int N = 160;
int used[N], mt[N], tmr, ans;
vector<int> g[N], p;

bool kuhn(int v) {
    if (used[v] == tmr)
        return false;
    used[v] = tmr;
    for (int to: g[v]) 
        if (mt[to] == -1) {
            mt[to] = v;
            return true;
        }   
    for (int to: g[v]) 
        if (kuhn(mt[to])) {
            mt[to] = v;
            return true;
        } 
    return false;
}

int main() {
	// read graph
	// check for bipartite
	// put vertices of one part in vector p
	memset(mt, -1, sizeof mt);
	for (int i: p) {
		tmr++;
		if (kuhn(i)) ans++;
	}
	cout << ans;  // ans - maximum bipartite matching
}
