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
template<class T> T min(T a, T b, T c) {
    return min(a, min(b, c));
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
int main()
{
    fastio();
    ll arr[3];
    ll n;
    cin >> n >> arr[0] >> arr[1] >> arr[2];
    sort(arr,arr+3);
    ll dp[n+2];
    for(ll i=0;i<=n+1;i++)
        dp[i] = LONG_MIN;
    //dp[arr[0]] = 1;
    dp[0] = 0;
    // for(ll i=0;i<=n;i++)
    //     cout << dp[i] << " " ;
    // cout << endl;
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<3;j++)
        {
            if(i+arr[j]<=n)
                dp[i+arr[j]] = max(dp[i+arr[j]],dp[i]+1);
        }
    //     for(ll i=0;i<=n;i++)
    //     cout << dp[i] << " " ;
    // cout << endl;
    }
    //cout << "HII" << endl;
    // for(ll i=0;i<=n;i++)
    //     cout << dp[i] << " " ;
    // cout << endl;
    cout << dp[n] << endl;
}
