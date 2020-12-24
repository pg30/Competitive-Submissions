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
	int n,t;
	cin >> n >> t;
	vector< pair<int,int> > arr;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		while(a<t)
			a+=b;
		arr.push_back({a,i});
	}
	sort(arr.begin(),arr.end());
	cout << arr[0].second+1 << endl;
}
