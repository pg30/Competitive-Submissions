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
#define mp make_pair
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
    string str;
    cin >> str;
    ll n = str.length();
    ll dp[n+1];
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<n;i++)
    {
        if(str[i]=='v' && str[i-1]=='v')
            dp[i] =dp[i-1]+1;
        else
            dp[i] = dp[i-1];
    }
    // for(char ch:str)
    //     cout << ch << " ";
    // cout << endl;
    // for(ll i=0;i<n;i++)
    //     cout << dp[i] << " ";
    // cout << endl;    
    ll prefix[n+1];
    memset(prefix,0,sizeof(prefix));
    for(ll i=1;i<n;i++)
        prefix[i]+=prefix[i-1]+dp[i];
    ll result = 0;
    // for(ll i=0;i<n;i++)
    //     cout << prefix[i] << " ";
    // cout << endl;
    for(ll i=0;i<n;i++)
    {
        if(str[i]=='o')
        {
            ll before,after;
            before = dp[i]-dp[0];
            after = dp[n-1]-dp[i];
            result+=before*after;            
        }
    }
    cout << result << endl;
    // for(ll i=0;i<n;i++)
    //     cout << dp[i] << " ";
    // cout << endl;
}
