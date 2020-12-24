#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	int n,b,a;
	cin >> n >> b >> a;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	int acap = a,steps=0;
	for(int i=0;i<n;i++)
	{
		if(a==0&&b==0)
			break;
		if(arr[i]==0)
		{
			if(a!=0)
				a--;
			else
				b--;
		}
		else
		{
			if(b==0 && a!=0)
				a--;
			else if(b!=0 && a!=acap)
			{
				b--;a++;
			}
			else if(b!=0 && a==acap)
				a--;
		}
		steps++;
	}
	cout << steps << endl;
}
