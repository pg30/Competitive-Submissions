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
int main()
{
    fastio();
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,s,t;
        cin >> n >> s >> t;
        ll a = s+t;
        if(a==n)
            cout << max(s,t)+1 << endl;
        else if(a>n)
        {
            s = s-(a-n);
            t = t-(a-n);
            cout << max(s,t)+1 << endl;
        }

    }
}
