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
	SieveOfEratosthenes(100);
	int n,m,i;
	cin >> n >> m;
	for(i=n+1;i<=100;i++)
	{
		if(prime[i])
			break;
	}
	if(m==i)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
