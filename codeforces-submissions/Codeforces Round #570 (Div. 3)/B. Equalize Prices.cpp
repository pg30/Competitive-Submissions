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
    ll q;
    cin >> q;
    while(q--)
    {
        ll n,k;
        cin >> n >> k;
        std::vector<ll> arr(n);
        for(ll i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        ll i = arr.size()-1;
        ll temp = arr[i];
        ll diff = arr[i]-arr[0];
        if(diff<=k)
            arr[i]+=k-diff;
        else
            arr[i]-=diff-k;
        if(abs(temp-arr[i])>k)
            cout << -1 << endl;
        else
            cout << arr[i] << endl;
    }
}
