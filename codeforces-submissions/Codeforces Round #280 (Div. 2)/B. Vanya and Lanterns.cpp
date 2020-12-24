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
	ll n,l;
	cin >> n >> l;
	vector<double> arr;
	for(ll i=0;i<n;i++)
	{
		double a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	double max1=0;
	for(ll i=0;i<n-1;i++)
	{
		if(arr[i+1]-arr[i] > max1)
			max1 = arr[i+1]-arr[i];
	}
	cout << fixed << setprecision(9) <<  max(max1/2,max(arr[0]-0,l-arr[n-1])) << endl;
}
