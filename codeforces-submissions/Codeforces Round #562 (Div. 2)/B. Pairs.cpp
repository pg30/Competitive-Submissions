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
        ll n,m;
        cin >> n >> m;
        std::vector<pair<ll,ll> > arr(m);
        for(ll i=0;i<m;i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        ll a1 = arr[0].first,a2 = arr[0].second,b1,b2;
        for(ll i=1;i<m;i++)
        {
            if(arr[i].first!=a1&&arr[i].second!=a1&&arr[i].first!=a2&&arr[i].second!=a2)
            {
                b1 = arr[i].first;
                b2 = arr[i].second;
                break;
            }
        }
        //cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
        ll flag=0;
        for(ll i=0;i<m;i++)
        {
            if(arr[i].first!=a1&&arr[i].first!=b1&&arr[i].second!=a1&&arr[i].second!=b1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout << "YES" << endl;
        else
        {
            flag=0;
            for(ll i=0;i<m;i++)
            {
                if(arr[i].first!=a1&&arr[i].first!=b2&&arr[i].second!=a1&&arr[i].second!=b2)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                cout << "YES" << endl;
            else
            {
                flag=0;
                for(ll i=0;i<m;i++)
                {
                    if(arr[i].first!=a2&&arr[i].first!=b1&&arr[i].second!=a2&&arr[i].second!=b1)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    cout << "YES" << endl;
                else
                {
                    flag=0;
                    for(ll i=0;i<m;i++)
                    {
                        if(arr[i].first!=a2&&arr[i].first!=b2&&arr[i].second!=a2&&arr[i].second!=b2)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                        cout << "YES" << endl;
                    else
                    {
                        cout << "NO" << endl;                
                    }
                }    
            }      
        }
    }
}
