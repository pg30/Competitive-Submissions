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
    std::vector<ll> arr(n+1),result;
    for(ll i=0;i<n;i++)
        cin >> arr[i];
    ll sum = accumulate(arr.begin(),arr.end(),0);
    sum = sum/2+1;
    if(arr[0]>=sum)
    {
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    sum-=arr[0];
    ll req = arr[0]/2;
    for(ll i=1;i<n;i++)
    {
        if(sum<=0)
            break;
        if(arr[i]<=req)
        {
            result.push_back(i+1);
            sum-=arr[i];
        }
    }
    result.push_back(1);
    if(sum>0 || result.size()==0)
        cout << 0 << endl;
    else
    {
        cout << result.size() << endl;
        for(ll a:result)
            cout << a << " ";
        cout << endl;
    }
}
