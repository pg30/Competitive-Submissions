#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	int n,a;
	cin >> n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	int sum=0;
	for(int i=0;i<n-1;i+=2)
	{
		if(arr[i]==arr[i+1])
			continue;
		else 
			sum = sum + abs(arr[i]-arr[i+1]);	
	}
	cout << sum << endl;	
}
