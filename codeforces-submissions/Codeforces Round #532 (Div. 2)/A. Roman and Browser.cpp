#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	int n,k,e=0,s=0;
	cin >> n >> k;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
		if(a==1)
			e++;
		else
			s++;
	}
	int a = e,b = s,c;
	int max = INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j+=k)
		{
			if(arr[j]==1)
				e--;
			else if(arr[j]==-1)
				s--;		
		}
//		cout << i << " " << e << " " << s << endl;
		for(int j=i-k;j>=0;j-=k)
		{
			if(arr[j]==1)
				e--;
			else if(arr[j]==-1)
				s--;		
		}
//		cout << i << " " << e << " " << s << endl;
		if(abs(e-s)>max)
		{
			max = abs(e-s);
//			cout << e << " " << s << " "; 
//			cout << max << " " << i << endl;
		}
		e = a;
		s = b;		
	}	
	cout << max << endl;
}
