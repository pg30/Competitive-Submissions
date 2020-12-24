/*      ###########################
        #  Author : Pranay Garg   #
        #  College : SGSITS       #
        ###########################
*/
# include   <bits/stdc++.h>
# include   <ext/pb_ds/assoc_container.hpp>
# define    ll                  long long int
# define    ull                 unsigned long long int
# define    double              long double
# define    sp(x,y)             fixed << setprecision(y) << x
# define    ironman             ios_base::sync_with_stdio(false);cin.tie(NULL);
# define    MOD                 1000000007
# define    MODT                998244353
# define    endl                '\n'
# define    clr(x,a)            memset(x,a,sizeof(x))
# define    ar                  array
# define    INF                 1000000000000000000ll + 239
# define    PI                  3.14159265358979323846
# define    fi                  first
# define    se                  second
# define    vi                  std::vector<ll>
# define    pb                  push_back
# define    pi                  pair<ll,ll>
# define    fo(i,n)             for(ll i=0;i<n;i++)
# define    all(a)              a.begin(), a.end()
# define    allr(a)             a.rbegin(), a.rend()
# define    alla(a,n)           a,a+n
# define    debug1(x)           cout<<#x<<" = "<<x<<endl;
# define    debug2(x,y)         cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<endl;
# define    debug3(x,y,z)       cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<endl;
# define    debug4(x,y,z,w)     cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<" "<<#w <<" = "<<w<<endl;
# define    debug5(x,y,z,w,v)   cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<" "<<#w <<" = "<<w<<" "<<#v <<" = "<<v<<endl;
# define    debug6(x,y,z,w,a,b) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<" "<<#w <<" = "<<w<<" "<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<endl;

# define    max(...)({ \
    ll nos[] = { __VA_ARGS__ }; \
    ll n = sizeof(nos)/sizeof(ll); \
    *std::max_element(&nos[0],&nos[n]); \
})

# define    min(...)({ \
    ll nos[] = { __VA_ARGS__ }; \
    ll n = sizeof(nos)/sizeof(ll); \
    *std::min_element(&nos[0],&nos[n]); \
})

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

template<typename... T>
void read(T&... args)
{
    ((cin >> args), ...);
}

template<typename... T>
void write(T... args)
{
    ((cout << args << " "), ...);
}

void fastio()
{
    ironman
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

//const int p1 = 13331,m1 = 1e9+9,p2 = 7919, m2 = 1e9+9;
//const int p1 = 97266353,m1 = 972663749,p2 = 97336357, m2 = 1000000007;
//const int p1 = 31 ,m1 = 1e9+7;

//grid cells
//D U R L
//ll dx[] = {1, -1, 0, 0};
//ll dy[] = {0, 0, 1, -1};
//ll dx[] = {-2,-2,-1,1,2,-2,1,-1};
//ll dy[] = {-1,1,2,2,1,-1,-2,-2};
//bool isSafe(ll x, ll y, ll n, ll m)
//{
//    return (x >= 0 && x < n && y >= 0 && y < m);
//}


//---------------TEMPLATE ABOVE--------------//
const int maxn = 2e5+5;
vi graph[maxn];
ll n;
vi parent,col,sub;
ll s,e;
bool dfs(ll node,ll par)
{
    col[node] = 1;
    for(auto i : graph[node])
    {
        if(i==par)
            continue;
        if(col[i]==0)
        {
            parent[i] = node;
            if(dfs(i,node))
                return 1;
        }
        else if(col[i]==1)
        {
            s = i;
            e = node;
            return 1;
        }
    }
    col[node] = 2;
    return 0;
}
map<ll,ll> res;
void util(ll node,ll par)
{
    sub[node] = 1;
    for(auto i : graph[node])
    {
        if(i==par || res.count(i)) continue;
        util(i,node);
        sub[node]+=sub[i];
    }
}
void solve()
{
    cin >> n;
    s=-1;e=-1;

    parent.assign(n,-1);
    res.clear();
    col.assign(n,0);
    sub.assign(n,0);
    for(ll i=0;i<n;i++)
        graph[i].clear();

    for(ll i=0;i<n;i++)
    {
        ll u,v;
        cin >> u >> v;
        u--;v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    ull ans = n*(n-1)/2;
    for(ll i=0;i<n;i++)
    {
        if(col[i]==0 && dfs(i,parent[i]))
            break;
    }
    ull sum = 0;
    vi cycle;
    cycle.pb(s);
    res[s] = 1;
    for(ll i=e;i!=s;i=parent[i])
    {
        cycle.pb(i);
        res[i] = 1;
    }
    ll curr = 0;
    for(auto i : cycle)
    {
        util(i,-1);
        sum+=sub[i];
    }
    for(auto i : cycle)
    {
        curr += sub[i]*(sum-sub[i]);
    }
    ans += curr/2;
    cout << ans << endl;
}
int main()
{
    fastio();
    ll t = 1;
    cin >> t;
    ll cases = t;
    while (t--)
    {
//        cout << "Case #" << cases-t << ": ";
        solve();
    }
}
 
