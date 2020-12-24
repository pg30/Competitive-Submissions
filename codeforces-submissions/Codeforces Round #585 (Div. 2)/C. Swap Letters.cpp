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
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define pb push_back
#define fi first
#define se second
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
int main()
{
    fastio();
    ll t=1;
    //cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        pair<ll,ll> a = {0,0};
        for(char ch:s)
        {
            if(ch=='a') a.fi++;
            else a.se++;
        }
        for(char ch:t)
        {
            if(ch=='a') a.fi++;
            else a.se++;
        }
        if(a.fi%2!=0||a.se%2!=0)
        {
            cout << -1 << endl;
            continue;
        }
        std::vector<ll> indexa,indexb;
        string s1,t1;
        for(ll i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                s1.pb(s[i]);
                t1.pb(t[i]);
                if(s[i]=='a') indexa.pb(i);
                else indexb.pb(i);
            }
        }
        if(s1.length()%2!=0)
        {
            cout << -1 << endl;
            continue;
        }
        std::vector<pair<ll,ll> > res;
        ll co = 0;
        for(ll i=0;i<indexa.size();i+=2)
        {
            if(i+1>=indexa.size())
                break;
            co++;
            res.pb({indexa[i+1],indexa[i]});
        }
        for(ll i=0;i<indexb.size();i+=2)
        {
            if(i+1>=indexb.size())
                break;
            co++;
            res.pb({indexb[i+1],indexb[i]});
        }
        if(indexa.size()%2!=0)
        {
            co+=2;
            res.pb({indexa[indexa.size()-1],indexa[indexa.size()-1]});
            res.pb({indexa[indexa.size()-1],indexb[indexb.size()-1]});
        }
        cout << co << endl;
        for(ll i=0;i<res.size();i++)
            cout << res[i].fi+1 << " " << res[i].se+1 << endl;
    }
}
