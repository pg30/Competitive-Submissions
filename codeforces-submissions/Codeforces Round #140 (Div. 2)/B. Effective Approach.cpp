#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool prime[101];
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
	ll n;
	cin >> n;
	vector<ll> arr,arr1(n+1,-1);
	for(ll i=0;i<n;i++)
	{
		ll a;
		cin >> a;
		arr1[a] = i;
		arr.push_back(a);
	}
	ll m,v=0,p=0;
	cin >> m;
	for(ll i=0;i<m;i++)
	{
		ll a;
		cin >> a;
		v+=arr1[a]+1;
		p+=n-arr1[a];
	}
	cout << v << " " << p << endl;
}
