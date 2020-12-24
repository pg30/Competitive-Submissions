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
ll ncr(ll n, ll k) 
{
  if(k>n)
    return 0; 
  if (k==0 || k==n) 
    return 1; 
  
  return  ncr(n-1, k-1) + ncr(n-1, k); 
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
    if (n & (1 << (i - 1))) 
        return true;
    else
        return false;
}
ll factorial(ll n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
}
int main()
{
    fastio();
    //ironman
    ll n,m;
    cin >> n >> m;
    ll arr1[n+1][m+1],arr2[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        arr1[i][m] = LONG_MAX;arr2[i][m] = LONG_MAX;
    }
    for(int i=0;i<=m;i++)
    {
        arr1[n][i] = LONG_MAX;arr2[n][i] = LONG_MAX;
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin >> arr1[i][j];
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin >> arr2[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ll a,b;
                a = min(arr1[i][j],arr2[i][j]);
                b = max(arr1[i][j],arr2[i][j]);
                arr1[i][j] = a;
                arr2[i][j] = b;
        }
    }
    //cout << arr1[0][3] << " " << arr2[0][3] << endl;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((arr1[i][j]>=arr1[i][j+1] || arr1[i][j]>=arr1[i+1][j])||(arr2[i][j]>=arr2[i][j+1] || arr2[i][j]>=arr2[i+1][j]))
            {
      //          cout << i << " " << j << endl;
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(flag==1)
    {
        cout << "Impossible" << endl;
    }
    else
        cout << "Possible" << endl;
}
