#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	ll x,y,z;
	cin >> x >> y >> z;
	ll a,b,c;
	cin >> a >> b >> c;
	if(x>a)
		cout << "NO" << endl;
	else
	{
		a=a-x;
		if(y>(a+b))
			cout << "NO" << endl;
		else
		{
			if((a+b-y+c)>=z)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}
