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
    ll arr[2*n];
    for(ll i=0;i<2*n;i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+2*n);
    int flag=0,sum1=0,sum2=0;
    for(ll i=0,j=2*n-1;i<2*n,j>=n;i++,j--)
    {
        sum1+=arr[i];
        sum2+=arr[j];
    }
    if(sum1==sum2)
        cout << -1 << endl;
    else
    {
        for(ll i=0;i<2*n;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}
