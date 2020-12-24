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
    ll t=1;
    //cin >> t;
    while(t--)
    {
        ll arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        ll a,ans=0;
        cin >> a;
        sort(arr,arr+3);
        if(arr[1]-arr[0] < a)
            ans+=a-arr[1]+arr[0];
        if(arr[2]-arr[1] < a)
            ans+=a-arr[2]+arr[1];
        cout << ans << endl;
    }    
}
