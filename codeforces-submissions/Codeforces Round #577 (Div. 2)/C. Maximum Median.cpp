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
bool prime[100005];
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
std::vector<ll> factors(ll n)//O(sqrt(n))
{
    std::vector<ll> f;
    for(ll i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            f.push_back(i);
            n = n/i;
        }
    }
    if(n>1) f.push_back(n);
    return f;
}
ll gcd(ll a,ll b)//O(logn)
{
    if(!b) return a;
    return gcd(b,a%b);
}
ll modpow(ll x,ll n,ll m)//O(logn)// used for calculating (x^n)%m
{
    if(n==0) return 1%m;
    ll u = modpow(x,n/2,m);
    u = (u%m * u%m)%m;
    if(n%2==1)
        u = (u%m * x%m)%m;
    return u%m;
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
ll modinverse(ll x,ll m)//O(logn)
{
    ll temp = eulerstotientfunction(m);
    return modpow(x,temp-1,m);
}
int main()
{
    fastio();
    ll n,k;
    cin >> n >> k;
    std::vector<ll> arr(n);
    for(ll i=0;i<n;i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end());
    ll start = arr[n/2],end = arr[n/2]+k+1,curr = arr[n/2];
    while(start<=end)
    {
        ll mid = start+(end-start)/2;
        ll ans = 0;
        for(ll i=n/2;i<n;i++)
        {
            if(arr[i]<mid)
                ans+=mid-arr[i];
        }
//        cout << mid << " " << ans << endl;
        if(ans<=k)
        {
            curr = max(curr,mid);
            start = mid+1;
        }
        else
            end = mid-1;
    }
    cout << curr << endl;
}
