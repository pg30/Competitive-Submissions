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
	ll n,m;
	cin >> n >> m;
	vector<int> arr;
	for(int i=0;i<m;i++)
	{
		ll a;
		cin >> a;
		arr.push_back(a);
	}
	ll current = 1,sum = 0;
	for(int i=0;i<m;i++)
	{
		if(arr[i]>=current)
		{
			sum+=arr[i]-current;
		}
		else
		{
			sum = sum+n-current+arr[i];
		}
		current = arr[i];
	}
	cout << sum << endl;
}
