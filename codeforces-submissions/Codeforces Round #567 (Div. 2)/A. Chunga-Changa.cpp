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
    ll x,y,z;
    cin >> x >> y >> z;
    ll ans = 0;
    ans+=x/z;ans+=y/z;
    x = x%z;y= y%z;
    if(x+y>=z)
    {
        ans+=(x+y)/z;
        if(x<y)
            cout << ans << " " <<  z-y << endl;
        else
            cout << ans << " " << z-x << endl;
    }
    else
    {
        cout << ans << " " << 0 << endl;
    }
}
