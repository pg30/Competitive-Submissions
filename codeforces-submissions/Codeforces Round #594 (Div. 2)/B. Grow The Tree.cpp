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
#define fi first
#define se second
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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
ll gcd(ll a,ll b)//O(logn)
{
    if(!b) return a;
    return gcd(b,a%b);
}
ll mulmod(ll a,ll b,ll mod)
{
    // ll res = 0;a = a%mod;
    // while(b>0)
    // {
    //     if(b%2==1)
    //         res = (res+a)%mod;
    //     a = (a*2)%mod;
    //     b = b/2;
    // }
    // return res%mod;
    return ((a%mod)*(b%mod))%mod;
}
ll modpow(ll x,ll n,ll m)//O(logn)// used for calculating (x^n)%m
{
    if(n==0) return 1%m;
    ll u = modpow(x,n/2,m)%m;
    u = ((u%m)*(u%m))%m;
    if(n%2==1)
        u = ((u%m)*(x%m))%m;
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
    //ll temp = eulerstotientfunction(m);
    return modpow(x,m-2,m);
}
ll ncr(ll n,ll k)
{
    ll res = 1;
    k = min(k,n-k);
    for(ll i=0;i<k;i++)
    {
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}
ll kadaneAlgo(const std::vector<ll> &arr,ll size)
{
    ll currmax=arr[0],maxsofar=arr[0];
    for(ll i=1;i<size;i++)
    {
        //debug2(currmax,maxsofar);
        currmax = max(arr[i],currmax+arr[i]);
        maxsofar = max(maxsofar,currmax);
    }
    return maxsofar;
}
std::vector<ll> zAlgo(string str)
{
//z[i] = longest substring starting at position i which
//is also prefix of the string O(m+n)
    std::vector<ll> z(str.length());
    ll n = str.length(),left=0,right=0;
    z[0] = 0;
    for(ll i=1;i<n;i++)
    {
        if(i>right)
        {
            left = right = i;
            while(right<n && str[right]==str[right-left])
                right++;
            z[i] = right-left;
            right--;
        }
        else
        {
            ll k = i-left;
            if(z[k]<right-i+1)
                z[i] = z[k];
            else
            {
                left = i;
                while(right<n && str[right]==str[right-left])
                    right++;
                z[i] = right-left;
                right--;
            }
        }
    }
    return z;
}
int main()
{
    fastio();
    ll t=1;
    //cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        std::vector<ll> arr(n);
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        sort(arr.begin(),arr.end());
        ll i=0,j=n-1;
        pair<ll,ll> point = {0,0};
        while(i<j)
        {
            point.fi+=arr[j];
            point.se+=arr[i];
            i++;j--;
        }
        if(n%2!=0)
            point.fi+=arr[i];
        //debug2(point.fi,point.se);
        cout << point.fi*point.fi+point.se*point.se << endl;
    }
}
