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
int solve(std::vector<ll> arr,ll i,ll sum,ll m)
{
    std::vector<ll> temp;
    for(ll j=0;j<i;j++)
        temp.push_back(arr[j]);
    sort(temp.rbegin(),temp.rend());
    ll count = 0;
    for(ll j=0;j<temp.size();j++)
    {
        if(sum<=m)
        {
            return count;
        }
        else
        {
            count++;
            sum-=temp[j];
        }
    }
    return count;
}
int main()
{
    fastio();
    ll n,m;
    cin >> n >> m;
    std::vector<ll> arr(n);
    ll sum = 0;
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];  
    }
    for(ll i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<m)
            cout << 0 << " ";
        else
        {
            cout << solve(arr,i,sum,m) << " ";
        }
    }
    cout << endl;
}
