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
        ll n;
        cin >> n;
        for(ll i=0;i<n;i++)
        {
            string a,b;
            cin >> a >> b;
            if(a.length()>b.length())
            {
                cout << "NO" << endl;
                continue;
            }
            ll j=0,k=0,flag=0;
            while(1)
            {
                if(j==a.length())
                    break;
                else if(a[j]!=b[k] && b[k]!=b[k-1])
                {
                    flag=1;
                    cout << "NO" << endl;
                    break;
                }
                else if(a[j]!=b[k] && b[k]==b[k-1])
                    k++;
                else if(a[j]==b[k]){ j++;k++; }
            }
            char ch = b[k-1];
            while(k!=b.length() && flag==0)
            {
                if(b[k]!=ch)
                {
                    flag=1;
                    cout << "NO" << endl;
                    break;
                }
                else
                    k++;
            }
            if(flag==0)
                cout << "YES" << endl;
        }
    }    
}
