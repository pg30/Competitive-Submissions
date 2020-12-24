/*      ###########################
        #  Author : Pranay Garg   #
        #  College : SGSITS       #
        ###########################
*/      
#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
void fastio()
{
    ironman
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
    #endif
}
ll nc[1001][1001];
ll ncr(ll n, ll k) 
{
    if(nc[n][k]!=-1)
        return nc[n][k]%1000000007;
  if(k>n)
    return (nc[n][k] = 0%1000000007); 
  if (k==0 || k==n) 
    return (nc[n][k] = 1%1000000007); 
  
  return  (nc[n][k] = (ncr(n-1, k-1)%1000000007 + ncr(n-1, k)%1000000007)%1000000007); 
}
bool prim[5005];vector<ll> prime;
void sieve(int n) 
{  
    memset(prim, true, sizeof(prime));   
    for (int p=2; p*p<=n; p++) 
    { 
        if (prim[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prim[i] = false; 
        } 
    }
    for(int i=2;i<=n;i++)
    {
        if(prim[i]==true)
            prime.push_back(i);
    }
}

bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
      for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}
bool powerOfTwo(int n)
{
    return (n&!(n&(n-1)));
}
int countone(int n)
{
    int count=0;
    while(n)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}
bool checkibit(ll n, ll i)
{
    if (n & (1 << i)) 
        return true;
    else
        return false;
}
ll factorial(ll n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
}
ll index = -1;
void binarySearch(ll arr[], ll low, ll high, ll x) 
{ 
    if (high >= low) 
    { 
        ll mid = low + (high - low)/2;  
        if (arr[mid]-arr[x]<=arr[x]) 
        {
            if(mid>index)
                index=mid;
            binarySearch(arr, (mid + 1), high, x); 
        }
        else
            binarySearch(arr, low, (mid -1), x); 
    } 
} 

int main()
{
    fastio();
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        ll a;
        cin >> a;
        if(a<0)
            a = -a;
        arr[i] = a;

    }
    sort(arr,arr+n);
    ll sum = 0;
    for(ll i=0;i<n-1;i++)
    {
        ll j=i;
        binarySearch(arr,i+1,n-1,i);
        j = index;
        index = -1;
        if(j!=-1)
            sum+=j-i;
    }
    cout << sum << endl;
}
