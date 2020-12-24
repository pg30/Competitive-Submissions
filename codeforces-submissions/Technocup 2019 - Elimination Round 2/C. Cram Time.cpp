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
ll parent[100005];
ll find(ll a)
{
    std::vector<ll> v;
    while(parent[a]>0)
    {
        v.push_back(a);
        a = parent[a];
    }
    for(ll i=0;i<v.size();i++)
        parent[v[i]] = a;
    return a;
}
bool prime[100005];
void SieveOfEratosthenes(int n) 
{  
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}  
void union1(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if(a!=b)
    {
        parent[a] = min(parent[a],parent[b]);
        parent[b] = a;
    }
}  
bool check(string str)
{
    for(ll i=0;i<str.length()-1;i++)
    {
        if(abs(str[i+1]-str[i])==1)
            return false;
    }
    return true;
}
void print(std::vector<ll> a)
{
    cout << a.size() << endl;
    for(ll i=0;i<a.size();i++)
        cout << a[i] << " " ;
    cout << endl;
}
int main()
{
    fastio();
    ll a1,b1;
    cin >> a1 >> b1;
    ll s = a1+b1;
    ll i=1,used=1;
    std::vector<ll> a,b;
    while(used<=s)
    {   
        i++;
        used+=i;
    }
    i--;
    for(ll j=i;j>=1;j--)
    {
        if(j<=a1)
        {
            a1-=j;
            a.push_back(j);
        }
        else
        {
            b1-=j;
            b.push_back(j);
        }
    }
    print(a);
    print(b);
}
