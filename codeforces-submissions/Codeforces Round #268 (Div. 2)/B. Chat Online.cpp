#include<bits/stdc++.h>
#define fast  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    fast;
	int p,q,l,r;
	cin >> p >> q >> l >> r;
	vector<int> arrp,arrq;
	for(int i=0;i<p;i++)
	{
		int a,b;
		cin >> a >> b;
		for(int j=a;j<=b;j++)
		{
			arrp.push_back(j);
		}
	}
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin >> a >> b;
		for(int j=a;j<=b;j++)
		{
			arrq.push_back(j);
		}
	}
	int count = 0;
	for(int i=l;i<=r;i++)
	{
		vector<int> copy(arrq.begin(),arrq.end()),copy1;
		for(int j=0;j<copy.size();j++)
		{
			copy[j]+=i;
		}
		set_intersection(arrp.begin(),arrp.end(),copy.begin(),copy.end(),back_inserter(copy1));
		if(copy1.size()!=0)
			count++;
	}
	cout << count << endl;
}
