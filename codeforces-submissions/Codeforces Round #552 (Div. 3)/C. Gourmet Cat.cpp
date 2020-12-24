#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	vector<int> a;
	for(int i=0;i<3;i++)
	{
		int arr;
		cin >> arr;
		a.push_back(arr);
	}
	int full = min({a[0]/3,a[1]/2,a[2]/2});
	a[0] = a[0]-3*full;
	a[1] = a[1]-2*full;
	a[2] = a[2]-2*full;
	vector<int> idx = {0,1,2,0,2,1,0};
	int ans=0;
	for(int start=0;start<7;start++)
	{
		int curr=0;
		int day=start;
		vector<int> b = a;
		while(b[idx[day]]>0)
		{
			b[idx[day]]--;
			curr++;
			day = (day+1)%7;
		}
		ans = max(ans,full*7+curr);
	}
	cout << ans << endl;
}
