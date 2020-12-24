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
	int n,m,h;
	cin >> n >> m >> h;
	vector<int> front,left;
	for(int i=0;i<m;i++)
	{
		int a;
		cin >> a;
		front.push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		left.push_back(a);
	}
	int top[n][m],topn[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int a;
			cin >> a;
			top[i][j] = a;
			topn[i][j]=0;
		}
	}
	for(int i=0;i<front.size();i++)
	{
		for(int j=0;j<n;j++)
		{
			if(top[j][i]==1 && left[j]>=front[i])
			{
				top[j][i] = front[i];
				break;
			}
		}
	}
	for(int i=0;i<left.size();i++)
	{
		for(int j=0;j<m;j++)
		{
			if(top[i][j]==1 && front[j]>=left[i])
			{
				top[i][j] = left[i];
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout << top[i][j] << " ";
		}
		cout << endl;
	}
}
