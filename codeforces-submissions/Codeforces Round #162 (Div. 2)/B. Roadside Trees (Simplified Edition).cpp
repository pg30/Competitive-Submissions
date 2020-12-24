#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool prime[101];
void fast_io()
{
	ironman;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
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

bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
      for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}

int main()
{
	ll n;
	cin >> n;
	vector<ll> arr;
	for(ll i=0;i<n;i++)
	{
		ll a;
		cin >> a;
		arr.push_back(a);
	}
	ll cost=0,height=0;
	for(ll i=0;i<n;i++)
	{
		if(height<=arr[i])
		{
			cost+=arr[i]-height+1;
			height = arr[i];
		}
		else
		{
			cost+=height-arr[i]+1;
			height = arr[i];
		}
	}
	cout << cost+n-1 << endl;
}
