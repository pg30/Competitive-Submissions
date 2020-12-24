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
    ll n;
    cin >> n;
    std::vector<ll> cost(n);
    for(ll i=0;i<n;i++)
        cin >> cost[i];
    sort(cost.begin(),cost.end());
    ll q;
    cin >> q;
    for(ll i=0;i<q;i++)
    {
        ll money;
        cin >> money;
        // ll start = 0,end = n-1,mid;
        // while(start<end)
        // {
        //     mid = start+(end-start)/2;
        //     if(cost[mid]>money)
        //         end = mid-1;
        //     else if(cost[mid]<=money)
        //         start = mid+1;
        // }
        // cout << mid << endl;
        cout << upper_bound(cost.begin(),cost.end(),money)-cost.begin() << endl;
    }
    //3 6 8 10 11
}
