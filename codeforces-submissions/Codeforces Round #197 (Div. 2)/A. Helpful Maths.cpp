#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool prime[101];
void SieveOfEratosthenes(int n) 
{  
    memset(prime, true, sizeof(prime));   
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
}
int main()
{
	ironman
	string str;
	cin >> str;
	vector<int> arr;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]!='+')
			arr.push_back(str[i]-'0');
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size()-1;i++)
	{
		cout << arr[i] << "+";
	}
	cout << arr[arr.size()-1];
}
