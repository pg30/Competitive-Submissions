#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std; 
int main()
{
	ironman
	int n,i;
	cin >> n;
	for(i=n+1;;i++)
	{
		int e=i;
		vector<int> arr;
		while(e>0)
		{
			arr.push_back(e%10);
			e = e/10;
		}
		set<int> s(arr.begin(),arr.end());
		if(s.size()==4)
			break;
	}
	cout << i << endl;
}
