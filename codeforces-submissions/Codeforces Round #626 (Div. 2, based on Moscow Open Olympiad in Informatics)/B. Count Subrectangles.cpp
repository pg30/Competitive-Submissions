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
#define se second
#define all(a) a.begin(), a.end()
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#w <<" "<<w<<endl;
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
        cout << i << endl;
    // cout << endl;
}
template<class T>
void printArray(T arr[],ll n)
{
    for(ll i=1;i<=n;i++)
        cout << arr[i] << " " ;
    cout << endl;
}
int main()
{
    fastio();
    ll t=1;
     //cin >> t;
    // ll cases = t;
    while(t--)
    {
        ll n,m,k;
        cin >> n >> m >> k;
        std::vector<ll> a(n),b(m);
        for(ll i=0;i<n;i++)
            cin >> a[i];
        for(ll i=0;i<m;i++)
            cin >> b[i];
        std::vector<ll> a1,b1;
        ll pref1[n+1]={0},pref2[m+1]={0};
        ll co = 0;
        for(ll i=0;i<n;i++)
        {
            if(a[i])
                co++;
            if(a[i]==0)
            {
                if(co)
                    a1.pb(co);
                co=0;
            }
        }
        if(co)
            a1.pb(co);
        co = 0;
        for(ll i=0;i<m;i++)
        {
            if(b[i])
                co++;
            if(b[i]==0)
            {
                if(co)
                    b1.pb(co);
                co=0;
            }
        }
        if(co)
            b1.pb(co);  
        for(auto i:a1)
        {
            for(ll j=1;j<=i;j++)
                pref1[j]+=i-j+1;
        }
        for(auto i:b1)
        {
            for(ll j=1;j<=i;j++)
                pref2[j]+=i-j+1;
        }
        // printVector(a1);
        // printVector(b1);
        // for(ll i=1;i<=n;i++)
        //     pref1[i]+=pref1[i-1];
        // for(ll i=1;i<=m;i++)
        //     pref2[i]+=pref2[i-1];   
        // printArray(pref1,n);
        // printArray(pref2,m);
        ll ans = 0;
        for(ll i=1;i*i<=k;i++)
        {
            if(k%i==0)
            {
                ll temp = k/i;
//                debug2(i,temp);
                if(i<=n && temp<=m)
                    ans+=pref1[i]*pref2[temp];
                if(i<=m && temp<=n && i!=temp)
                    ans+=pref1[temp]*pref2[i];
            }
        }
        cout << ans << endl;


        // cout << "Case " << cases-t << ": " << endl;
        //fprintf(stderr,"Time: %d ms\n", (int)(clock()*1000.0/CLOCKS_PER_SEC));
    }
}
