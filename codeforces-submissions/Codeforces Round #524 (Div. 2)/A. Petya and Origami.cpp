#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll int n,k,res=0;
	cin >> n >> k;
	ll int r=2*n,g=5*n,b=8*n;
	if(r%k==0)
		res = res+r/k;
	else
		res = res+r/k+1;
	if(g%k==0)
		res = res+g/k;
	else
		res = res+g/k+1;
	if(b%k==0)
		res = res+b/k;
	else
		res = res+b/k+1;
	cout << res << endl;
}
