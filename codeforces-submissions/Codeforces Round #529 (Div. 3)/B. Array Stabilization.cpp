#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	int n;
	cin >> n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	int d = arr[n-1]-arr[0];
	int min1 = arr[n-1]-arr[1];
	int min2 = arr[n-2]-arr[0];
	cout << min(min1,min2) << endl;;
}
