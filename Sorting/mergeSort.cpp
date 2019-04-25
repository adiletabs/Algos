#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
int a[N];
 
void Merge(int l, int m, int r) 
{
    int i, j, k, cur[r - l + 1];
    i = l, k = 0, j = m + 1;
    while (i <= m && j <= r) 
    {
        if (a[i] < a[j]) 
            cur[k++] = a[i++];
        else 
            cur[k++] = a[j++];
    }
    while (i <= m) 
        cur[k++] = a[i++];
    while (j <= r) 
        cur[k++] = a[j++];
    for(int i = l; i <= r; i++) 
        a[i] = cur[i - l];
}
 
void MergeSort(int l, int r) 
{
    if(l < r) 
    {
        int m = l + (r - l) / 2;
        MergeSort(l, m);
        MergeSort(m + 1, r);
        Merge(l, m, r);
    }
}
