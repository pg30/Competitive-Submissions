#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool isPrime(ll n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
int main()
{
	ironman
	ll n,m;
	cin >> n >> m;
	vector<ll> arr,arr1;
	for(int i=0;i<m;i++)
	{
		ll a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	if(m==0)
		cout << "YES" << endl;
	else
	{
		if(arr[0]==1||arr[m-1]==n)
			cout << "NO" << endl;
		else
		{
			int flag=0;
			for(int i=0;i<m-2;i++)
			{
				if(arr[i+1]==arr[i]+1 && arr[i+2]==arr[i]+2)
				{
					cout << "NO" << endl;
					flag=1;
					break;
				}
			}
			if(!flag)
				cout << "YES" << endl;
		}
	}
}
