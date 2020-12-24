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
#define INF 1e18L+1
using namespace std;
template<class T> T max(T a, T b, T c) {
    return max(a, max(b, c));
}
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
ll dp[100007];
ll arr[100007];
ll n;
int main()
{
    fastio();
    memset(arr,0,sizeof(arr));
    cin >> n;
    for(ll i=0;i<n;i++)
    {
        ll a;
        cin >> a;
        arr[a]++;
    }
    memset(dp,0,sizeof(dp));
    dp[1] = arr[1];
    //dp[i] denotes that max score till ith number
    for(ll i=2;i<=100006;i++)
    {
        dp[i] = max(dp[i-1],i*arr[i]+dp[i-2]);
    }
    cout << dp[100006] << endl;
}
