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
    while(t--)
    {
        ll n,m;
        cin >> n >> m;
        string str;
        cin >> str;
        std::vector<ll> arr(m);
        for(ll i=0;i<m;i++)
            cin >> arr[i];
        ll count[n][26];
        memset(count,0,sizeof(count));
        for(ll i=0;i<n;i++)
        {
            if(i==0)
            {
                count[i][str[i]-'a']++;
            }
            else
            {
                for(ll j=0;j<26;j++)
                    count[i][j]=count[i-1][j];
                count[i][str[i]-'a']++;
            }
        }
        ll ans[26];
        memset(ans,0,sizeof(ans));
        for(ll i=0;i<m;i++)
        {
            ll a=arr[i];
            for(ll j=0;j<26;j++)
            {
                ll co = count[a-1][j];
                //debug2(char(j+'a'),co);
                ans[j]+=co;
            }
        }
        for(ll j=0;j<26;j++)
            ans[j]+=count[n-1][j];
        printArray(ans,26);


        // cout << "Case " << cases-t << ": " << endl;
//        fprintf(stderr, "Time: %d ms\n", (int)(clock()*1000.0/CLOCKS_PER_SEC));
    }
}   
