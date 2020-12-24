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
	ll n;
	cin >> n;
	vector<ll> arr;
	for(ll i=0;i<n;i++)
	{
		ll a;
		cin >> a;
		arr.push_back(a);
	}
	ll a=-1,b=-1;
	for(ll i=0;i<n-1;i++)
	{
		if(arr[i+1]<arr[i])
		{
			a = i;
			break;
		}
	}
	for(ll i=n-1;i>0;i--)
	{
		if(arr[i-1]>arr[i])
		{
			b = i;
			break;
		}
	}
	//cout << a << " " << b << endl;
	int flag = 0;
	reverse(arr.begin()+a,arr.begin()+b+1);
	for(ll i=0;i<n-1;i++)
	{
		if(arr[i+1]<arr[i])
		{
			flag=1;
			cout << "no" << endl;
			break;
		}
	}
	if(flag==0)
	{
		cout << "yes" << endl;
		if(a!=-1 && b!=-1)
			cout << a+1 << " " << b+1 << endl;
		else
			cout << 1 << " " << 1 << endl;
	}
}
