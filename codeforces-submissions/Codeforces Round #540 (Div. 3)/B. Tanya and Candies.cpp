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
	ll n,odd=0,even=0;
	cin >> n;
	vector<ll> arr;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin >> a;
		if((i+1)%2==0)
			even+=a;
		else
			odd+=a;
		arr.push_back(a);
	}
	ll count = 0,even1=0,odd1=0;
	for(int i=0;i<n;i++)
	{
		if(i!=0)
		{
			even = even-even1;
			even = even+odd1;
			odd = odd-odd1;
			odd = odd+even1;
		}
		if((i+1)%2==0)
		{
			even = even-arr[i];
			//even1 = even1+arr[i];
		}
		else
		{
			odd = odd-arr[i];
			//odd1 = odd1+arr[i];
		}
		//cout << even << " " << odd << endl;
		if(even==odd)
			count++;
			even = even+even1;
			even = even-odd1;
			odd = odd+odd1;
			odd = odd-even1;
		if((i+1)%2==0)
		{
			//even = even-arr[i];
			even1 = even1+arr[i];
			even = even+arr[i];
		}
		else
		{
			//odd = odd-arr[i];
			odd1 = odd1+arr[i];
			odd = odd+arr[i];
		}
	}
	/*for(int i=0;i<n;i++)
	{
		if((i+1)%2==0)
		{
			even1 = even-arr[i];
			odd1 = odd;
		}
		else
		{
			odd1 = odd-arr[i];
			even1 = even;
		}
		for(int j = i-1;j>=0;j--)
		{
			if((j+1)%2==0)
			{
				even1 = even1 - arr[j];
				odd1 = odd1 + arr[j];
			}
			else
			{
				even1 = even1 + arr[j];
				odd1 = odd1 - arr[j];
			}
		}
		if(even1==odd1)
			count++;
	}*/
	cout << count << endl;
}
