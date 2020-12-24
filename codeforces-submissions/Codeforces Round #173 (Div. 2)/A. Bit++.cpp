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
	int x = 0;
	cin >> n;
	while(n--)
	{
		char a,b,c;
		cin >> a >> b >> c;
		if(a=='X')
		{
			if(b=='+')
				x++;
			else
				x--;
		}
		else
		{
			if(a=='+')
				x++;
			else
				x--;
		}
	}
	cout << x << endl;
}
