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
ll morowow(ll x,ll n,ll m)//O(logn)// used for calculating (x^n)%m
{
    if(n==0) return 1%m;
    ll u = morowow(x,n/2,m);
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
    //ll temp = eulerstotientfunction(m);
    return morowow(x,m-2,m);
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
void update(std::vector<std::vector<ll> > &bit,ll n,ll i,char ch,ll val)
{
    i++;
    while(i<n)
    {
        bit[i][ch-'a']+=val;
        i += (i&(-i));
    }
}
ll query(const std::vector<std::vector<ll> > &bit,ll n,ll l,ll r)
{
    ll i = r;
    i++;
    std::vector<ll> arr(26,0);
    while(i>0)
    {
        for(ll j=0;j<26;j++)
            arr[j]+=bit[i][j];
        i-=(i&(-i));
    }
    i = l;
    while(i>0)  
    {
        for(ll j=0;j<26;j++)
        {
            arr[j]-=bit[i][j];
        }
        i-=(i&(-i));
    }
    ll co = 0;
    for(i=0;i<26;i++)
    {
        if(arr[i]>0)
        {
            //cout << char(i+'a');
            co++;
        }
    }
//    cout << endl;
    return co;
}
int main()
{
    fastio();
    ll t=1;
    //cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        ll n = str.length();
        std::vector<std::vector<ll> > bit(n+1,std::vector<ll>(26,0));
        ll q;
        cin >> q;
        for(ll i=0;i<n;i++)
            update(bit,n+1,i,str[i],1);
        while(q--)
        {
//            cout << "HIII" << endl;
            ll type;
            cin >> type;
            //debug1(type);
            if(type==1)
            {
                ll pos;
                char ch;
                cin >> pos >> ch;
                pos--;
                update(bit,n+1,pos,str[pos],-1);
                str[pos] = ch;
                update(bit,n+1,pos,ch,1);
            }
            else if(type==2)
            {
                ll l,r;
                cin >> l >> r;
                l--;r--;
                //cout << "DDD";
                ll ans = query(bit,n+1,l,r);
                cout << ans << endl;
            }
        }
    }
}
