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
ll parent[100005],size[100005];
std::vector<ll> arr(100005);
void make_set(ll a)
{
    parent[a]=a;
    size[a]=1;
}
ll find(ll a)
{
    if(parent[a]==a)
        return a;
    return parent[a] = find(parent[a]);
}
void unionf(ll a,ll b)
{
    a = find(a);
    b = find(b);
    if(a!=b)
    {
        if(arr[a]<arr[b])
        {
            parent[b] = a;
        }
        else
            parent[a] = b;
    }
}
int main()
{
    fastio();
    ll t=1;
    //cin >> t;
    //ll cases = t;
    while(t--)
    {
        ll n;
        cin >> n;
        std::vector<pair<ll,string> > arr(n);
        for(ll i=0;i<n;i++)
        {
            cin >> arr[i].fi >> arr[i].se;
        }
        bool ok = true;
        string prev = "North";
        ll dist = 0;
        for(ll i=0;i<n;i++)
        {
            if(dist==0 && arr[i].se!="South")
            {
                ok = false;
                break;
            }
            if(dist==20000 && arr[i].se!="North")
            {
                ok = false;
                break;
            }
            if(arr[i].se=="East" || arr[i].se=="West")
                continue;
            if(dist>20000 || dist<0)
            {
                ok = false;
                break;
            }
            if((arr[i].se=="North" && prev=="South") || (prev==arr[i].se && prev=="North"))
                dist-=arr[i].fi;
            if((arr[i].se=="South" && prev=="North") || (prev==arr[i].se && prev=="South"))
                dist+=arr[i].fi;
            prev = arr[i].se;
        }   
        if(dist!=0 || prev!="North")
            ok = false;
        if(!ok)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

        // cout << "Case " << cases-t << ": " << endl;
//        fprintf(stderr, "Time: %d ms\n", (int)(clock()*1000.0/CLOCKS_PER_SEC));
    }
}   
