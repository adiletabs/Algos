/*---------------------------------------------------------

Euler's Totient function

Counts positive integers up to a given integer N
that are relatively prime to N

1st method: counting for only one given number - 
get_phi(N) function
Time complexity - O(sqrt(N))

2nd method: precalculation for all numbers up to given N
Time complexity - O(Nloglog(N))
Access to phi[i] - O(1)

---------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int get_phi(int n)
{
	int res = n, i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			res -= res / i;
		}
		i++;
	}
	if (n > 1)
		res -= res / n;
	return res;
}

const int N = 100100;   
int phi[N];      
                        
void calc()            
{                       
    for (int i = 1; i < N; i++) 
        phi[i] = i; 
    for (int p = 2; p < N; p++) 
    { 
        if (phi[p] == p) 
        { 
            phi[p] = p - 1; 
            for (int i = 2 * p; i < N; i += p) 
                phi[i] = (phi[i] / p) * (p - 1); 
        } 
    }  
}

int main()
{
	calc();
	int T;
	cin >> T;
	while (T--) {
		int x;
		cin >> x;
		if (get_phi(x) == phi[x]) 
			cout << "True " << phi[x] << '\n';
	}
}