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
    ll n;
    cin >> n;
    ll arr[n],total=0;
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
        if(arr[i]==1) total++;
    }
    ll ans = 0;
    pair<ll,ll> dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    if(arr[0]==1)
    {
        dp[0][0].first = 0;
        dp[0][0].second = 1;
    }
    else
    {
        dp[0][0].first = 1;
        dp[0][0].second = 0;   
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=i;j<n;j++)
        {
            if(j==0) continue;
            if(arr[j]==1)   
            {
                dp[i][j].first = dp[i][j-1].first;
                dp[i][j].second = dp[i][j-1].second+1;
            }
            else
            {
                dp[i][j].first = dp[i][j-1].first+1;
                dp[i][j].second = dp[i][j-1].second;
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=i;j<n;j++)
        {
            //cout << dp[i][j].first << "+" << dp[i][j].second << " " ;
            ans = max(ans,total-dp[i][j].second+dp[i][j].first);
        }
//        cout << endl;
    }
    cout << ans << endl;
}
