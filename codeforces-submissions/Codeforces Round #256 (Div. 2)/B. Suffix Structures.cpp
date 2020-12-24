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
	string s,t;
	cin >> s >> t;
	if(s.length()<t.length())
		cout << "need tree" << endl;
	else
	{
		map<char,int> mps,mpt;int flag=0;
		for(int i=0;i<t.length();i++)
			mpt[t[i]]++;
		for(int i=0;i<s.length();i++)
			mps[s[i]]++;
		if(s.length()==t.length())
		{
			for(int i=0;i<s.length();i++)
			{
				if(mps[s[i]]!=mpt[s[i]])
				{
					cout << "need tree" << endl;
					flag=1;
					break;
				}
			}
			if(!flag)
			cout << "array" << endl;
		}
		else if(s.length()>t.length())
		{
			flag=0;
			for(int i=0,j=0;i<s.length();i++)
			{
				if(s[i]==t[j])
				{
					j++;
					if(j==t.length())
					{
						flag=1;
						break;	
					}	
				}	
			}
			if(flag)
				cout << "automaton" << endl;
			else
			{
				flag=0;
				for(int i=0;i<t.length();i++)
				{
					if(mps[t[i]]<mpt[t[i]])
					{
						flag=1;
						cout << "need tree" << endl;
						break;
					}
				}
				if(!flag)
				{
					cout << "both" << endl;
				}
			}	
			
		}
	}
}
