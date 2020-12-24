#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	ll n,v;
	cin >> n >> v;
	n--;
//	ll a = n/v,cost=0,i=1,n1=0;
	if(v>=n)
	{
		cout << n << endl;
	}
	else
	{
		ll fuel = v,cost = v,i=2,dist = v;
		while(dist<n)
		{
			dist++;
			cost+=i;
			i++;
		}
		cout << cost << endl;
	}
}
