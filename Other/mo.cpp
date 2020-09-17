/*--------------------------------------------------------

An algorithm for solving different 
types of range queries problems

Time complexity - O(N * sqrt(N)) * max(O(add), O(remove))

--------------------------------------------------------*/


#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

int root;

struct query {
	int l, r, id;

	bool operator < (const query &qr) {
		int block1 = (l - 1) / root, block2 = (qr.l - 1) / root;
		if (block1 == block2) {
			if (block1 % 2 == 0) return r < qr.r;
			return r > qr.r;
		}
		return block1 < block2;
	}
} q[N];

int n, m, a[N], ans[N];

void add(int pos) {
	// implementation is specific for each problem
}

void remove(int pos) {
	// implementation is specific for each problem
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].id = i;
	}
	root = sqrt(n);
	sort(q, q + m);
	int L = 1, R = 0;
	for (int i = 0; i < m; i++) {
		while (L > q[i].l) {
			add(L - 1);
			L--;
		}
		while (R < q[i].r) {
			add(R + 1);
			R++;
		}
		while (L < q[i].l) {
			remove(L);
			L++;
		}
		while (R > q[i].r) {
			remove(R);
			R--;
		}
		ans[q[i].id] = res;
 	}
 	for (int i = 0; i < m; i++)
 		cout << ans[i] << '\n';
}
