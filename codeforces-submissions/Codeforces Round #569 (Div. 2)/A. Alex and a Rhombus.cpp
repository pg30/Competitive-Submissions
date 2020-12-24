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
    //cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        std::vector<ll> arr(n+1);
        arr[1] = 1;
        for(ll i=2;i<=n;i++)
        {
            arr[i] = (8*(i-1))/2+arr[i-1];
        }
        cout << arr[n] << endl;
    }
}
