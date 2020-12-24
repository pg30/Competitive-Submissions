/*      ###########################
        #  Author : Pranay Garg   #
        #  College : SGSITS       #
        ###########################
*/      
#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1000000007
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
int main()
{
    fastio();
    ll n,even=0,odd=0;
    cin >> n;
    ll arr[n+1];
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
        if(arr[i]%2==0)
            even++;
        else
            odd++;
    }
    if(even==n)
    {
        for(ll i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    else if(odd==n)
    {
        for(ll i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    else
    {
        sort(arr,arr+n);
        for(ll i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}
