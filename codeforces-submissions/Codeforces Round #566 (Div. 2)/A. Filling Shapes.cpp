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
    ll t = 1;
    while(t--)
    {
        int n;
        cin >> n;
        if(n%2!=0)
            cout << 0 << endl;
        else
        {
            ll a = n/2,ans=1;
            for(ll i=0;i<a;i++)
                ans = ans*2;
            cout << ans << endl;
        }
    }
}
