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
	int n;
	cin >> n;
	int sum = 0,c = 0;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		sum+=a;
	}
	for(int i=1;i<=5;i++)
	{
		int r = sum+i;
		if(r%(n+1)!=1)
			c++;
	}
	cout << c << endl;
}
