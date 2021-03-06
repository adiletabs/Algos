/*----------------------------------

Bubble-sort algorithm

Time complexity - O(N^2)
Additional space complexity - O(1)

----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

const int N = 5050;
int a[N];

void bubbleSort(int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}
