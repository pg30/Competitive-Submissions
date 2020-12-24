#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll int n,s,result=0;
	cin >> n >> s;
	if(s%n==0)
		cout << s/n << endl;
	else
	{
		result = result+s/n;
		while((s%n)>=n)
		{
			result = result+s/n;
			s = s%n;
		}
		if((s%n)<n)
			result = result+1 ;
		cout << result << endl;
	}
}
