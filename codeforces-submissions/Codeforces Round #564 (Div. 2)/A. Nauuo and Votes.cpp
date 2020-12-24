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
    ll ans = x-y;
    if(x+z<y)
        cout << "-" << endl;
    else if(y+z<x)
        cout << "+" << endl;
    else if(z==0 && x==y)
        cout << "0" << endl;
    else
        cout << "?" << endl;
}
