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
    if(k>n) return 0;
    ll res = 1;
    k = min(k,n-k);
    for(ll i=1;i<=k;i++)
    {
        res *= (n-i+1);
        res/=i;
    }
    return res;
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
void decrease(string &str)
{
    ll i = str.length()-1;
    while(i>0 && str[i]=='0')
    {
        str[i]='9';
        i--;
    }
    str[i] = str[i]-1;
//    debug1(str);
}
string num;
ll co[10];
string check()
{
    string temp = num;
    for(ll i=0;i<=9;i++)
    {
        for(ll j=0;j<co[i];j++)
            temp+=(i+'0');
    }
    return temp;
}
int main()
{
    fastio();
    ll t=1;
    //cout << "hii";
    //cin >> t;
    ll cases = t;
    while(t--)
    {
        string a,b;
        cin >> a >> b;
        //debug2(a,b);
        if(a.length()<b.length())
        {
            sort(a.begin(),a.end());
            reverse(a.begin(),a.end());
            cout << a << endl;
            continue;
        }
        memset(co,0,sizeof(co));
        for(char ch:a)
            co[ch-'0']++;
        for(ll j=0;j<a.length();j++)
        {
            for(ll i=9;i>=0;i--)
            {
                if(co[i]>0)
                {
                    num+=(i+'0');
                    co[i]--;
                    if(check()<=b) break;
                    num.erase(num.end()-1);
                    co[i]++;
                }
            }   
        }  
        cout << num << endl;

//        cout << "Case " << cases-t << ": ";
    }  
}
