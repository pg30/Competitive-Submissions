/*      ###########################
        #  Author : Pranay Garg   #
        #  College : SGSITS       #
        ###########################
*/
# include   <bits/stdc++.h>
# include   <ext/pb_ds/assoc_container.hpp>
# define    ll                  long long int
# define    ull                 unsigned long long int
# define    ironman             ios_base::sync_with_stdio(false);cin.tie(NULL);
# define    MOD                 1000000007
# define    endl                '\n'
# define    INF                 1e18
# define    PI                  3.14159265358979323846
# define    mp                  make_pair
# define    fi                  first
# define    se                  second
# define    vi                  std::vector<ll>
# define    vii(a)              std::vector<a>
# define    pb                  push_back
# define    pi                  pair<ll,ll>
# define    fo(i,a,b)           for(ll i=a;i<b;i++)
# define    all(a)              a.begin(), a.end()
# define    allr(a)             a.rbegin(), a.rend()
# define    alla(a,n)           a,a+n
# define    debug1(x)           cout<<#x<<" "<<x<<endl;
# define    debug2(x,y)         cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
# define    debug3(x,y,z)       cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
# define    debug4(x,y,z,w)     cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#w <<" "<<w<<endl;
# define    debug5(x,y,z,w,v)   cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#w <<" "<<w<<" "<<#v <<" "<<v<<endl;
# define    debug6(x,y,z,w,a,b) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#w <<" "<<w<<" "<<#a<<" "<<a<<" "<<#b<<b<<endl;

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

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
    freopen("error.txt", "w", stderr);
#endif
}

bool prime[10000005];
void SieveOfEratosthenes(ll n)//O(nloglogn)
{
    memset(prime, true, sizeof(prime));

    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
bool isPrime(ll n)//O(sqrt(n))
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
std::vector<ll> generatePrimeFactors(ll n)
{
    std::vector<ll> prime;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            prime.pb(i);
            while (n % i == 0)
                n = n / i;
        }
    }
    if (n != 1)
        prime.pb(n);
    return prime;
}
std::vector<ll> generateFactors(ll n)
{
    std::vector<ll> fact;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            fact.pb(i);
            if (n / i != i)
                fact.pb(n / i);
            //24 - 1,2,3,4,6,8,12
        }
    }
    fact.pb(1);
    if (n != 1)
        fact.pb(n);
    sort(fact.begin(), fact.end());
    return fact;
}

ll extendedGCD(ll a, ll b, ll &x, ll &y)
{
    //produces correct results for negative integers as well
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1, d;
    d = extendedGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
ll gcd(ll a, ll b) //O(log min(a,b))
{
    /*
    recursive implementation below
    if(!b) return a;
    return gcd(b,a%b);
    */

    //non-recursive implementation below
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll multiply(ll a, ll b, ll m);
ll singlemod(ll a, ll m);
ll modpow(ll x, ll n, ll m) //O(logn)// used for calculating (x^n)%m
{
    if (n == 0)
        return 1;
    ll res = 1;
    while (n)
    {
        if (n % 2)
            res = multiply(res, x, m);
        x = multiply(x, x, m);
        n = n >> 1;
    }
    return singlemod(res, m);
}
ll modinverse(ll x, ll m) //O(logn)
{
    return modpow(x, m - 2, m);
}
ll add(ll a, ll b, ll m)
{
    return (((a % m) + (b % m)) % m);
}
ll substract(ll a, ll b, ll m)
{
    // if (a < b)
    //     swap(a, b);
    return (((a % m) - (b % m) + m) % m);
}
ll multiply(ll a, ll b, ll m)
{
    return (((a % m) * (b % m)) % m);
}
ll divide(ll a, ll b, ll m)
{
    ll temp = modinverse(b, m);
    return multiply(a, temp, m);
}
ll singlemod(ll a, ll m)
{
    return (a % m);
}
ll eulerstotientfunction(ll n)//O(sqrt(n))
{
    ll ans = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n = n / i;
            ans -= ans / i;
        }
    }
    if (n > 1)
        ans -= ans / n;
    return ans;
}

ll ncr(ll n, ll k, ll m)
{
    if (k > n) return 0;
    ll res = 1;
    k = min(k, n - k);
    for (ll i = 1; i <= k; i++)
    {
        res = multiply(res, n - i + 1, m);
        res = divide(res, i, m);
        // res *= (n-i+1);
        // res/=i;
    }
    return singlemod(res, m);
}
ll kadaneAlgo(const std::vector<ll> &arr)
{
    ll size = arr.size();
    ll currmax = arr[0], maxsofar = arr[0];
    for (ll i = 1; i < size; i++)
    {
        //debug2(currmax,maxsofar);
        currmax = max(arr[i], currmax + arr[i]);
        maxsofar = max(maxsofar, currmax);
    }
    return maxsofar;
}
ll getDigitSum(ll n)
{
    ll co = 0;
    while (n > 0)
    {
        co += n % 10;
        n = n / 10;
    }
    return co;
}

template<class T>
void printVector(const std::vector<T> arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}
template<class T>
void printArray(T arr[], ll n)
{
    for (ll i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//grid cells
//D U R L
//ll dx[] = {1, -1, 0, 0};
//ll dy[] = {0, 0, 1, -1};

//---------------TEMPLATE ABOVE--------------//
void solve()
{
    ll n, k;
    cin >> n >> k;
    vi arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    ll mini = *min_element(all(arr)), maxi = *max_element(all(arr));
    ll cnt[maxi + 1] = {0};
    for (auto i : arr)
        cnt[i]++;
    for (ll i = maxi - 1; i >= 1; i--)
        cnt[i] += cnt[i + 1];

    if (maxi == mini)
    {
        cout << 0 << endl;
        return;
    }

    ll ans = 0, sum = 0, prev = 0;
    for (ll i = maxi; i > mini; i--)
    {
        sum += cnt[i];
        if (sum > k)
        {
            ans++;
            sum = cnt[i];
        }
    }
    ans++;
    cout << ans << endl;
}
int main()
{
    fastio();
    ll t = 1;
//    cin >> t;
    ll cases = t;
    while (t--)
    {
        // cout << "Case #" << cases-t << ": ";
        solve();
    }
}
