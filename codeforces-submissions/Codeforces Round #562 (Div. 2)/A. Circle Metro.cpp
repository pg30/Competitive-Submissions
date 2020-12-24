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
        int n,a,x,b,y,flag=0;
        cin >> n >> a >> x >> b >> y;
        while(1)
        {
            if(a==n+1)
                a=1;
            if(b==0)
                b=n;
            if(a==b)
            {
                cout << "YES" << endl;
                flag=1;
                break;
            }
            if(a==x||b==y)
                break;
            a++;b--;
        }
        if(flag==0)
            cout << "NO" << endl;
    }
}
