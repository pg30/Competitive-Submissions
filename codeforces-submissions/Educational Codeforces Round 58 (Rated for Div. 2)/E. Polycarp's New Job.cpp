#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	ll n;
	cin >> n;
	char a;
	ll b,c,min1 = LONG_MIN,max1 = LONG_MIN;
	vector<ll> arr1,arr2;
	while(n--)
	{
		cin >> a >> b >> c;
		if(a=='+')
		{
			if(min(b,c)>min1)
				min1 = min(b,c);
			if(max(b,c)>max1)
				max1 = max(b,c);
		}
		else if(a=='?')
		{
			if(min(b,c)<min1 || max(b,c)<max1)
			{
				cout << "NO" <<endl;
			}
			else
				cout << "YES" << endl;
		}
	}
}
