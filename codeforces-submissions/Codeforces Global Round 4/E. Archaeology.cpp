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
    string str,result,temp;
    cin >> str;
    ll n = str.length();
    ll i=0,j=n-1;
    while(i<=j)
    {
        if(str[i]==str[j])
        {
            result.push_back(str[i]);
            i++;j--;
        }
        else if(str[i]==str[j-1])
        {
            result.push_back(str[i]);
            i++;j-=2;
        }
        else if(str[i+1]==str[j])
        {
            result.push_back(str[i+1]);
            i+=2;j--;
        }
        else
        {
            i++;j--;
        }
    }
    temp = result;
    //cout << temp << endl;
    temp.pop_back();
    reverse(temp.begin(),temp.end());
    //result += temp;
    cout << result << temp << endl;
    // if(result.size()%2==0)
    // {
    //     reverse(result.begin(),result.end());
    //     cout << result << endl;
    // }
    // else
    // {
    //     if(result.size()>1)
    //     {
    //         for(ll i = result.size()-2;i>=0;i--)
    //             cout << result[i];
    //     }
    //     cout << endl;
    // }
}
