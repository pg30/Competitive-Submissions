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
	map<string,string> mp;
	for(int i=0;i<m;i++)
	{
		string str1,str2;
		cin >> str1 >> str2;
		mp[str1] = str2;
	}
	for(int i=0;i<n;i++)
	{
		string str;
		cin >> str;
		if(mp[str].length()<str.length())
			cout << mp[str] << " ";
		else
			cout << str << " ";
	}
}
