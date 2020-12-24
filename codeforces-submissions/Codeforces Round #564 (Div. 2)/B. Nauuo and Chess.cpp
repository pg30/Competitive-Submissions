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
    ll n;
    cin >> n;
    ll a = n/2;
    a++;
    cout << a << endl;
    ll i1 = 1,i2 = 1;
    ll flag = 0;
    for(ll i=1;i<=n;i++)
    {
        cout << i1 << " " << i2 << endl;
        if(flag==0)
        {
            i2++;
            flag=1;
        }
        else
        {
            i1++;
            flag=0;
        }
    }
}
