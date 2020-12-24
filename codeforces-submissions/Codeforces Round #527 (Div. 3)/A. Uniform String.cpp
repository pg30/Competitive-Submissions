#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		char a='a';
		cin >> n >> k;
		int j,i=1,flag=0;
		j = n/k;
			for(int l=1;l<=k;l++)
			{
				for(int b=1;b<=j;b++)
					cout << a;
				a++;
			}
			int d = n%k;
			for(i=1;i<=d;i++)
				cout << "a";
//			count++;
			cout << endl;
	}
}
