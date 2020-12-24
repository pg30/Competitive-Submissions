#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int cnt_ones(int val)
{
	int ret=0;
	while(val>0)
	{
		ret++;
		val=val&(val-1);
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);// Used for fast IO
	cin>>n>>m>>k;
	vector<int> v(m);
	int i,val,ans=0;
	for(i=0;i<m;i++) cin>>v[i]; 
	cin>>val;
	for(i=0;i<m;i++) if(cnt_ones(val^v[i])<=k) ans++;
	cout << ans << "\n";
	return 0;
}
