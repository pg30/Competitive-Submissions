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
ll c = pow(2,32);
int main()
{
    fastio();
    ll ans = 0;
    ll l;
    cin >> l;
    stack<ll> st;
    st.push(1);
    ll flag=0;
    for(ll i=0;i<l;i++)
    {
        string a;
        cin >> a; 
        if(a=="end")
        {
            st.pop();
        }
        else if(a=="add")
        {
            ans+=st.top();
            //cout << ans << endl;
        }
        else
        {
            ll temp;
            cin >> temp;
                ll num = st.top();
                // if(temp*num>=pow(2,32))
                //     flag=1;
                st.push(min(temp*num,c));
        }
    }
    if(ans<c)
        cout << ans << endl;
    else
        cout << "OVERFLOW!!!" << endl;
}
