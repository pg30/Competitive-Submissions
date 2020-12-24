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
ll suma(ll n)
{
    ll temp = n;
    ll sum1 = 0;
    //cout << temp << endl;
    while(temp!=0)
    {
        sum1+=(temp%10);
        temp = temp/10;
    }
    return sum1;
}
int main()
{
    fastio();
    ll n;
    cin >> n;
    //cout << n << endl;
    while(suma(n)%4!=0)
    {
        n++;
    }
    cout << n << endl;
}
