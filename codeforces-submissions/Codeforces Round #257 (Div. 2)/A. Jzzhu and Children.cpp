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
	int n,m;
	cin >> n >> m;
	vector<ll> arr;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin >> a;
		arr.push_back(a);
	}
	int max = 0,last;
	for(int i=0;i<n;i++)
	{
		if(arr[i]/m >= max)
		{
			if(arr[i]%m!=0)
			{
				max = arr[i]/m;
				last = i+1;
			}
			else
			{
				if(arr[i]/m!=max)
				{
					max = arr[i]/m-1;
					last = i+1;
				}
			}
		}
	}
	cout << last << endl;
}
