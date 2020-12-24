#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int q;
	cin >> q;
	while(q--)
	{
		ll int l,r;
		cin >> l >> r;
		ll int sum = 0;
		if(l==r)
		{
			if(l%2==0)
				sum = sum+l;
			else
				sum = sum-l;
		}
		else
		{
			ll int l1,r1,l2,r2,odd,even;
			if(l%2==0)
			{
				l1 = l+1;
				l2 = l;
			}
			else
			{
				l1 = l;
				l2 = l+1;
			}
			if(r%2==0)
			{
				r1 = r-1;
				r2 = r;
			}
			else
			{
				r1 = r;
				r2 = r-1;
			}
			odd = (r1-l1)/2+1;
			even = r-l-odd+1;
	//out << odd << " " << even << " " << " " << l1 << " " << r1 << " " << l2 << " " << r2 << " " << endl;
			if(odd==even)
			{
				if(l%2==0)
					sum = sum+(-1)*(odd);
				else
					sum = sum+odd;
			}
			else if(odd>even)
			{
				sum = sum+even-r;
			}
			else if(even>odd)
			{
				sum = sum-odd+r;
			}
		}
		cout << sum << endl;
	}
}
