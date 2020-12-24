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
	string str;
	cin >> str;
	unordered_map<char,int> mp;
	for(int i=0;i<str.length();i++)
	{
		mp[str[i]]++;
	}
	int count=0;
	unordered_map<char,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		if((it->second)%2!=0)
			count+=it->second;
	}
	if(count==0||count==1)
		cout << "First" << endl;
	else if(count%2==0)
		cout << "Second" << endl;
	else	
		cout << "First" << endl;
}
