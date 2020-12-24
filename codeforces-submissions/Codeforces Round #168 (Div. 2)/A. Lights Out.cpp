#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std; 
int main()
{
	ironman
	int arr[5][5]={0};
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin >> arr[i][j];
		}
	}
	int sum = 0;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			sum = 0;
			sum = arr[i][j]+arr[i-1][j]+arr[i+1][j]+arr[i][j+1]+arr[i][j-1];
			if(sum%2==0)
				cout << 1;
			else
				cout << 0;
		}
		cout << endl;
	}
}
