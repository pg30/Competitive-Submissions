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
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >> n >> m;
        char arr[n][m];
        ll row[n],col[m];
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                cin >> arr[i][j];
                if(arr[i][j]=='*')
                    row[i]++,col[j]++;
            }
        }
        for(ll i=0;i<n;i++)
        {
            row[i] = n-row[i];
        }
        for(ll i=0;i<m;i++)
        {
            col[i] = m-col[i];
        }
        // sort(row,row+n);
        // sort(col,col+m);
        ll result = LONG_MAX;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                ll a = row[i]+col[j];
                if(arr[i][j]=='.')
                    a--;
                if(a<0)
                    a++;
                result = min(result,a);
            }
        }
        cout << result << endl;
    }
}
