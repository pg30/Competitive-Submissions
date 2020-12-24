#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	int q;
	cin >> q;
	for(int i=0;i<q;i++)
	{
		ll l,r,d;
		cin >> l >> r >> d;
		if(d<l)
			cout << d << endl;
		else if(d>r)
			cout << d << endl;
		else
		{
			ll b = r%d;
			if(b==0)
				cout << r+d << endl;
			else
				cout << d*((r/d)+1) << endl;
		}
	}
}
