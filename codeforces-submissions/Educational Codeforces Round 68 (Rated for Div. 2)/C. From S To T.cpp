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
int main()
{
    fastio();
    ll t1;
    cin >> t1;
    while(t1--)
    {
        string s,t,p;
        cin >> s >> t >> p;
        unordered_map<char,ll> m1,m2,m3;
        for(char ch:s)
            m1[ch]++;
        for(char ch:t)
        {
            m2[ch]++;
        }
        for(char ch:p)
            m3[ch]++;
        ll i=0,j=0,flag=0;
        string final;
        while(j<t.length())
        {
            if(s[i]==t[j])
            {
                final.push_back(s[i]);
                i++;j++;
            }
            else
            {
                if(m3[t[j]]==0)
                {
                    flag=1;
                    break;
                }
                else
                {
                    m3[t[j]]--;
                    final.push_back(t[j]);
                    j++;
                }
            }
        }
        while(i<s.length())
        {
            final.push_back(s[i]);
            i++;
        }
        //cout << final << " " << t << endl;
        if(final!=t)
            flag=1;
        if(!flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
