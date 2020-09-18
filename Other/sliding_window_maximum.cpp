/*--------------------------------------------------------

An algorithm for finding maximum value of each segment 
of size k in an integer array with linear time complexity

Time complexity - O(N)

--------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

const int N = 200100;

int n, k, a[N];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	deque<int> dq;
	for (int i = 1; i <= k; i++) {
		while (!dq.empty() && a[i] >= a[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}	
	for (int i = k + 1; i <= n; i++) {
		cout << a[dq.front()] << ' ';
		while (!dq.empty() && dq.front() <= i - k)
			dq.pop_front();
		while (!dq.empty() && a[i] >= a[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	cout << a[dq.front()];
}
