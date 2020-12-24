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
int main()
{
    fastio();
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    ll ans = 0;
    for(ll i=1;i<n;i++)
    {
        if(arr[i-1]==1)
        {
            if(arr[i]==2) ans+=3;
            if(arr[i]==3) ans+=4;
        }
        else if(arr[i-1]==2)
        {
            if(arr[i]==1) ans+=3;
            else
            {
                cout << "Infinite" << endl;
                return 0;
            }
        }
        else if(arr[i-1]==3)
        {
            if(arr[i]==1) ans+=4;
            else
            {
                cout << "Infinite" << endl;
                return 0;
            }
            if(arr[i]==1 && arr[i+1]==2)
                ans--;
        }
    }
    cout << "Finite" << endl;
    cout << ans << endl;
}
