#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool prime[101];

ll ncr(ll n, ll k) 
{
  if(k>n)
  	return 0; 
  if (k==0 || k==n) 
    return 1; 
  
  return  ncr(n-1, k-1) + ncr(n-1, k); 
}

void SieveOfEratosthenes(int n) 
{  
    memset(prime, true, sizeof(prime));   
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
}

int main()
{
	ironman
	ll n,m;
	cin >> n >> m;
	ll a,b=0;
	if(n%m==0)
	{
		a = n/m;
		ll min = m*(a*(a-1)/2);
		ll max = (n-m+1)*(n-m)/2;
		cout << min << " " << max << endl;
	}
	else
	{
		a = n/m;
		b = n%m;
		//cout << a << " " << b << endl;
		//cout << ncr(a+b,2) << endl;
		ll min = m*a*(a-1)/2+a*b;
		ll max = (n-m+1)*(n-m)/2;
		cout << min << " " << max << endl;
	}
}
