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
#define INF 0x7fffffff
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define alla(a,n) a,a+n
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#w <<" "<<w<<endl;
#define debug5(x,y,z,w,v) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#w <<" "<<w<<" "<<#v <<" "<<v<<endl;
#define debug6(x,y,z,w,a,b) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#w <<" "<<w<<" "<<#a<<" "<<a<<" "<<#b<<b<<endl;
#define pb push_back
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
bool prime[10000005];
void SieveOfEratosthenes(ll n)//O(nloglogn) 
{  
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}  
bool isPrime(ll n)//O(sqrt(n))
{
    if(n<2)
        return false;
    for(ll i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}
std::vector<ll> generatePrimeFactors(ll n)
{
    std::vector<ll> prime;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            prime.pb(i);
            while(n%i==0)
                n=n/i;
        }   
    }
    if(n!=1)
        prime.pb(n);
    return prime;
}
std::vector<ll> generateFactors(ll n)
{
    std::vector<ll> fact;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            fact.pb(i);
            if(n/i!=i)
                fact.pb(n/i);
            //24 - 1,2,3,4,6,8,12
        }
    }
    fact.pb(1);
    if(n!=1)
        fact.pb(n);
    sort(fact.begin(),fact.end());
    return fact;
}
ll gcd(ll a,ll b)//O(logn)
{
    if(!b) return a;
    return gcd(b,a%b);
}
ll multiply(ll a,ll b,ll m);
ll singlemod(ll a,ll m);
ll modpow(ll x,ll n,ll m)//O(logn)// used for calculating (x^n)%m
{
    if(n==0)
        return 1;
    ll res = 1;
    while(n)
    {
        if(n%2)
            res = multiply(res,x,m);
        x = multiply(x,x,m);
        n = n>>1;
    }
    return singlemod(res,m);
}
ll modinverse(ll x,ll m)//O(logn)
{
    return modpow(x,m-2,m);
}
ll add(ll a,ll b,ll m)
{
    return (((a%m)+(b%m))%m);
}
ll substract(ll a,ll b,ll m)
{
    if(a<b)
        swap(a,b);
    return (((a%m)-(b%m)+m)%m);
}
ll multiply(ll a,ll b,ll m)
{
    return (((a%m)*(b%m))%m);
}
ll divide(ll a,ll b,ll m)
{
    ll temp = modinverse(b,m);
    return multiply(a,temp,m);
}
ll singlemod(ll a,ll m)
{
    return (a%m);
}
ll eulerstotientfunction(ll n)//O(sqrt(n))
{
//    debug1(n);
    ll ans = n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n = n/i;
            ans -= ans/i;
        }
    }
    if(n>1)
        ans -= ans/n;
//    debug1(ans);
    return ans;
}
ll ncr(ll n,ll k,ll m)
{
    if(k>n) return 0;
    ll res = 1;
    k = min(k,n-k);
    for(ll i=1;i<=k;i++)
    {
        res = multiply(res,n-i+1,m);
        res = divide(res,i,m);
        // res *= (n-i+1);
        // res/=i;
    }
    return singlemod(res,m);
}
ll kadaneAlgo(const std::vector<ll> &arr)
{
    ll size = arr.size();
    ll currmax=arr[0],maxsofar=arr[0];
    for(ll i=1;i<size;i++)
    {
        //debug2(currmax,maxsofar);
        currmax = max(arr[i],currmax+arr[i]);
        maxsofar = max(maxsofar,currmax);
    }
    return maxsofar;
}
ll getDigitSum(ll n)
{
    ll co = 0;
    while(n>0)
    {
        co+=n%10;
        n = n/10;
    }
    return co;
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
        cout << arr[i] << " ";
    cout << endl;
}
struct node
{
    ll gc,mini,co;
};
std::vector<node> segment_tree(4*100005);
std::vector<ll> arr(100005);
node united(node a,node b)
{
    node papa;
    papa.gc = gcd(a.gc,b.gc);
    papa.mini = min(a.mini,b.mini);
    papa.co=0;
    if(papa.mini==a.mini)
        papa.co+=a.co;
    if(papa.mini==b.mini)
        papa.co+=b.co;
    return papa;
}
void build(ll index,ll start,ll end)
{
    if(start>end)
        return;
    if(start==end)
    {
        segment_tree[index].gc=arr[start];
        segment_tree[index].mini=arr[start];
        segment_tree[index].co=1;
        return;        
    }
    ll mid = start+(end-start)/2;
    build(2*index+1,start,mid);
    build(2*index+2,mid+1,end);
    segment_tree[index] = united(segment_tree[2*index+1],segment_tree[2*index+2]);
    return;
}
node query(ll index,ll start,ll end,ll qstart,ll qend)
{
    node res;
    res.gc = 0; res.mini = INT_MAX; res.co = 0;
    if(start>end || start>qend || end<qstart)
        return res;
    if(start>=qstart && end<=qend)
        return segment_tree[index];
    ll mid = start+(end-start)/2;
    return united(query(2*index+1,start,mid,qstart,qend),query(2*index+2,mid+1,end,qstart,qend));
}
int main()
{
    fastio();
    ll t=1;
    //cin >> t;
    // ll cases = t;
    while(t--)  
    { 
        ll n;
        cin >> n;
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        ll q;
        cin >> q;
        build(0,0,n-1);
        for(ll i=0;i<q;i++)
        {
            ll a,b;
            cin >> a >> b;
            a--;
            b--;
            node aa = query(0,0,n-1,a,b);
//            debug3(aa.mini,aa.gc,aa.co);
            ll ans = 0;
            if(aa.mini==aa.gc)
                ans = b-a+1-aa.co;
            else
                ans = b-a+1;
            cout << ans << endl;
        }

        // cout << "Case " << cases-t << ": " << endl;
        //fprintf(stderr,"Time: %d ms\n", (int)(clock()*1000.0/CLOCKS_PER_SEC));
    }
}