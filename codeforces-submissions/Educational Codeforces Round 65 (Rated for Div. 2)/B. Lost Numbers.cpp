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
int main()
{
//fastio();
    int arr1[] = {4,8,15,16,23,42};
    unordered_map<int, pair<int,int> > mp;
    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<6;j++)
        {
            mp[arr1[i]*arr1[j]] = {arr1[i],arr1[j]};
        }
    }
    int arr2[50] = {0};
    int arr[6];
    fflush(stdout);
    int a,b,c,d;
    cout << "? "  << 1 << " " << 2 << endl;
    fflush(stdout);
    cin >> a;
    fflush(stdout);
    cout << "? " <<  2 << " " << 3 << endl;
    fflush(stdout);
    cin >> b;
    fflush(stdout);

    if(mp[a].first==mp[b].first)
    {
        arr[1] = mp[a].first;
        arr[0] = mp[a].second;
        arr[2] = mp[b].second;
    }
    else if(mp[a].first==mp[b].second)
    {
        arr[1] = mp[a].first;
        arr[0] = mp[a].second;
        arr[2] = mp[b].first;
    }
    else if(mp[a].second==mp[b].first)
    {
        arr[1] = mp[b].first;
        arr[0] = mp[a].first;
        arr[2] = mp[b].second;
    }
    else if(mp[a].second==mp[b].second)
    {
        arr[1] = mp[a].second;
        arr[0] = mp[a].first;
        arr[2] = mp[b].first;
    }
    arr2[arr[1]] = 1;arr2[arr[0]] = 1;arr2[arr[2]] = 1;


    cout << "? " <<  3 << " " << 4 << endl;
    fflush(stdout);
    cin >> c;
    fflush(stdout);
    cout << "? " << 4 << " " << 5 << endl;
    fflush(stdout);
    cin >> d;
    fflush(stdout);
    if(mp[c].first==mp[d].first)
    {
        arr[3] = mp[c].first;
        arr[2] = mp[c].second;
        arr[4] = mp[d].second;
    }
    else if(mp[c].first==mp[d].second)
    {
        arr[3] = mp[c].first;
        arr[2] = mp[c].second;
        arr[4] = mp[d].first;
    }
    else if(mp[c].second==mp[d].first)
    {
        arr[3] = mp[d].first;
        arr[2] = mp[c].first;
        arr[4] = mp[d].second;
    }
    else if(mp[c].second==mp[d].second)
    {
        arr[3] = mp[c].second;
        arr[2] = mp[c].first;
        arr[4] = mp[d].first;
    }
    arr2[arr[3]] = 1;arr2[arr[2]] = 1;arr2[arr[4]] = 1;
    cout << "! ";
    fflush(stdout);
    for(int i=0;i<5;i++)
        cout << arr[i] << " ";
    fflush(stdout);
    for(int i=0;i<6;i++)
    {
        if(arr2[arr1[i]]==0)
        {
            cout << arr1[i] << endl;
            break;
        }
    }
    fflush(stdout);
}
