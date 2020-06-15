/*----------------------------------

Merge-sort algorithm

Time complexity - O(NlogN)
Additional space complexity - O(N)

----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N], n;
 
void merge(int l, int r) {
    int cur[r - l + 1], mid = l + r >> 1;
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) cur[k++] = a[i++];
        else cur[k++] = a[j++];
    }
    while (i <= mid) cur[k++] = a[i++];
    while (j <= r) cur[k++] = a[j++];
    for(int i = l; i <= r; i++) 
        a[i] = cur[i - l];
}
 
void mergeSort(int l, int r) {
    if (l < r) {
        int mid = l + r >> 1;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, r);
    }
}

int main() {   
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}
