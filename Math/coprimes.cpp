#include <bits/stdc++.h>
using namespace std;

// based on  Euler’s Totient Function

typedef long long ll;

const int N = 100100;   // calc() calculates ans[i] - 
ll phi[N], ans[N];      // number of unordered co-prime pairs
                        // in range [1, i] for any i in [1, N)
void calc()            
{                       
    for (ll i = 1; i < N; i++) 
        phi[i] = i; 
    for (ll p = 2; p < N; p++) 
    { 
        if (phi[p] == p) 
        { 
            phi[p] = p - 1; 
            for (ll i = 2 * p; i < N; i += p) 
                phi[i] = (phi[i] / p) * (p - 1); 
        } 
    }  
    for (ll i = 1; i < N; i++) 
        ans[i] = ans[i - 1] + phi[i]; 
}
