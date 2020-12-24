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
	ll t;
	cin >> t;
	while(t--)
	{
		ll n,a,b;
		cin >> n >> a >> b;
		ll result,result1;
		result = (n/2)*b;
		result1 = n*a;
		if(n%2!=0)
			result = result + a*(n%2);
		//cout << result << " " << result1 << endl;
		cout << min(result,result1) << endl;
	}
}
