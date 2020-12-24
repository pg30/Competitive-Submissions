#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	ll n;
	cin >> n;
	if(n==1)
		cout << 2 << endl;
	else if(n==2)
		cout << 3 << endl;
	else
	{
		int j=3,a=4,i=2;
		while(n>j)
		{
			for(int k=0;k<2;k++)
			{
				j+=i;
				a++;
				if(n<j)
				{
					a--;
					break;
				}
				else if(n==j)
					break;
			}
			i++;
		}
		cout << a << endl;
	}
}
