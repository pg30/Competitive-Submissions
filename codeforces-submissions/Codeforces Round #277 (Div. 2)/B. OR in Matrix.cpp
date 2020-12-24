#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool isPrime(ll n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
int main()
{
	ironman
	int m,n;
	cin >> m >> n;
	int arr[m][n],arr1[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=1;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int a;
			cin >> a;
			arr1[i][j] = a;
	//		cout << arr[i][j] << endl;
			if(a==0)
			{
				 for(int k=0;k<m;k++)
				 {
				 	arr[k][j]=0;
				 }
				 for(int k=0;k<n;k++)
				 {
				 	arr[i][k]=0;
				 }
			}
		}
	}
	int flag=0,flag1=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr1[i][j]==1)
			{
				flag=0;
				for(int k=0;k<n;k++)
				{
					if(arr[i][k])
					{
						flag=1;
						break;
					}
				}
				if(!flag)
				{
					for(int k=0;k<m;k++)
					{	
						if(arr[k][j])
						{
							flag=1;
							break;
						}
					}
				}
				if(!flag)
				{
					flag1=1;
					break;
				}
			}
			if(flag1)
			break;
		}
	}
	if(flag1==0)
	{
		cout << "YES" << endl;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
		cout << "NO" << endl;
}
