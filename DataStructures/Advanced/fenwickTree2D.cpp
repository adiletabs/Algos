#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2020;

int n, m;
ll a[N][N], t[N][N][4], d[4];

void add(int x, int y, ll val) {
	d[0] = val, d[1] = val * (1 - y), d[2] = val * (1 - x), d[3] = val * (1 - x) * (1 - y);
    for (int i = x; i <= n; i |= i + 1)
        for (int j = y; j <= m; j |= j + 1) 
        	for (int k = 0; k < 4; k++)
        		t[i][j][k] += d[k];
}

void add(int leftTopX, int leftTopY, int rightBottomX, int rightBottomY, ll val) {
	add(leftTopX, leftTopY, val);
    add(rightBottomX + 1, rightBottomY + 1, val);
    add(rightBottomX + 1, leftTopY, -val);
    add(leftTopX, rightBottomY + 1, -val);
}

ll get(int x, int y) {
    d[0] = d[1] = d[2] = d[3] = 0;
    for (int i = x; i > 0; i = (i & (i + 1)) - 1)
    	for (int j = y; j > 0; j = (j & (j + 1)) - 1)
        	for (int k = 0; k < 4; k++)
        		d[k] += t[i][j][k];	
    return d[0] * x * y + d[1] * x + d[2] * y + d[3];
}

ll get(int leftTopX, int leftTopY, int rightBottomX, int rightBottomY) {
	return get(rightBottomX, rightBottomY) - 
			get(leftTopX - 1, rightBottomY) - 
			get(rightBottomX, leftTopY - 1) + 
			get(leftTopX - 1, leftTopY - 1);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			add(i, j, i, j, a[i][j]);
		}
	int q; cin >> q;
	while (q--) {
		string com; 
		int x1, y1, x2, y2;
		cin >> com >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		if (com == "add") {
			ll val; cin >> val;
			add(x1, y1, x2, y2, val);
		} else if (com == "sum") {
			cout << get(x1, y1, x2, y2) << '\n';
		}
	}
}
