/*      ###########################
        #  Author : Pranay Garg   #
        #  College : SGSITS       #
        ###########################
*/      
#include <bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1000000007 
#define endl '\n'
#define INF 1e18L+1
#define mp make_pair
#define fi first
#define all(a) a.begin(), a.end()
#define se second
#define pb push_back
#define pf push_front
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#w <<" "<<w<<endl;
#define debug5(x,y,z,w,u) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#w <<" "<<w<<" "<<#u<<" "<<u<<endl;
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
template<class T>
void printVector(const std::vector<T> arr)
{
    for(auto i:arr)
        cout << i << " ";
    cout << endl;
}
template<class T>
void printArray(T arr[],ll n)
{
    for(ll i=0;i<n;i++)
        cout << arr[i] << " " ;
    cout << endl;
}
int main()
{
    fastio();
    ll t=1;
    cin >> t;
    //ll cases = t;
    std::vector<ll> fact[20001];
    for(ll i=1;i<20001;i++)
    {
        for(ll j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                fact[i].pb(j);  
                if(i/j!=j)
                    fact[i].pb(i/j);
            }
        }
        fact[i].pb(1);
        if(i!=1)
            fact[i].pb(i);
         sort(all(fact[i]));
    }
    while(t--)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        ll ans = INF;
        pair<ll,pair<ll,ll> > fin;
        for(ll i=1;i<20001;i++)
        {
            for(ll j=0;j<fact[i].size();j++)
            {
                for(ll k=0;k<fact[fact[i][j]].size();k++)
                {
                    ll a1 = fact[fact[i][j]][k],b1 = fact[i][j],c1 = i;
                    if(a1>c1) swap(a1,c1);
                    if(a1>b1) swap(a1,b1);
                    if(b1>c1) swap(b1,c1);
                    ll temp=abs(a-a1)+abs(b-b1)+abs(c-c1);
                    //debug3(c,b,a);
                    //debug5(i,fact[i][j],fact[fact[i][j]][k],temp,ans);
                    if(temp<ans)
                    {
                        ans = temp;
                        fin = {a1,{b1,c1}};
//                        cout << fin.fi << " " << fin.se.fi << " " << fin.se.se << endl;
                    }
                }
            }
        }
        cout << ans << endl;
        ll arr[3] = {fin.fi,fin.se.fi,fin.se.se};
        sort(arr,arr+3);
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

        // cout << "Case " << cases-t << ": " << endl;
//        fprintf(stderr, "Time: %d ms\n", (int)(clock()*1000.0/CLOCKS_PER_SEC));
    }
}   
