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
	int n;
	cin >> n;
	string str;
	cin >> str;
	if(n%2!=0)
	{
		cout << ":(" << endl;
		return 0;
	}
	if(str[0]==')'||str[n-1]=='(')
	{
		cout << ":(" << endl;
		return 0;
	}
	str[0]='(';str[n-1]=')';
	int open=0,close=0;
	for(int i=1;i<n-1;i++)
	{
		if(str[i]=='(')
			open++;
		else if(str[i]==')')
			close++;
	}
	n-=2;
	int missing = n-(open+close);
	int a,b=open-close;
	missing = missing-(open-close);
	a = missing/2;b+=missing/2;
	//cout << open << " " << close << " " << a << " " << b << endl;
	n+=2;
	int sum = 1,c=0,d=0;
	for(int i=1;i<n-1;i++)
	{
		if(str[i]=='(')
		{
			sum+=1;
		}
		else if(str[i]==')')
			sum-=1;
		else
		{
			if(c!=a)
			{
				str[i] = '(';
				sum+=1;
				c++;
			}
			else if(d!=b)
			{
				str[i] = ')';
				sum-=1;
				d++;
			}
		}
		if(sum==0)
		{
			cout << ":(" << endl;
			return 0;
		}
	}
	sum-=1;
	if(sum==0)
		cout << str << endl;
	else
	{
		cout << ":(" << endl;
	//	cout << str << endl;
	//	cout << a << " " << b << " " << c << " " << d << endl;
	}
}
