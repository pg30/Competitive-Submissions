/*      ###########################
        #  Author : Pranay Garg   #
        #  College : SGSITS       #
        ###########################
*/      
#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1000000007
#define endl '\n'
using namespace std;
void fastio()
{
    ironman
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
    #endif
}
ll parent[100005];
ll find(ll a)
{
    std::vector<ll> v;
    while(parent[a]>0)
    {
        v.push_back(a);
        a = parent[a];
    }
    for(ll i=0;i<v.size();i++)
        parent[v[i]] = a;
    return a;
}
bool prime[100005];
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
void union1(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if(a!=b)
    {
        parent[a] = min(parent[a],parent[b]);
        parent[b] = a;
    }
}  
bool check(string str)
{
    for(ll i=0;i<str.length()-1;i++)
    {
        if(abs(str[i+1]-str[i])==1)
            return false;
    }
    return true;
}
int main()
{
    fastio();
    ll n,z;
    cin >> n >> z;
    std::vector<ll> arr(n);
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    ll l=0,r = n/2;
    while(l<=r)
    {
        ll mid = (l+r)/2;
        bool good = true;
        for(ll i=0;i<mid;i++)
        {
            good &= (abs(arr[i]-arr[i+n-mid])>=z);
        }
        if(good)
            l = mid+1;
        else
            r = mid-1;
    }
    cout << r <<  endl;
}
