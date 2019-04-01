#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
vector<int> g[N];
int subtrees[N];   // subtrees[i] - size of subtree
				   // of i-th vertex in a tree

void get_subtrees(int v, int e)      // start from (root, root)
{                           // in directed graph parameter e can be omitted 
    subtrees[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
    	int to = g[v][i];
        if (to == e)
            continue;
        get_subtrees(to, v);
        subtrees[v] += subtrees[to];
    }
}
