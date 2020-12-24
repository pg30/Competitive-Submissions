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
int ans = INT_MIN;
int solve(int arr[],int n,int i,int res)
{
    if(i==n)
    {
        ans = max(ans,res);
        return 1;
    }
    int a = solve(arr,n,i+1,arr[i]*res);
    int b = solve(arr,n,i+1,-(arr[i]+1)*res);
    //cout << a << " " << b << endl;
}
int main()
{
    fastio();
    ll n;
    cin >> n;
    ll count = 0;
    std::vector<ll> arr(n);
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
        //cout << arr[i] << endl;
        if(arr[i] >= 0)
        {
        //    cout << arr[i] << endl;
            arr[i] = -arr[i]-1;
        //    cout << arr[i] << endl;
        }
        if(arr[i]==-1)
            count++;
    }
    if(n%2==1)
    {
        if(count>0)
        {
            int flag=0;
            ll min = LONG_MAX;
            for(ll i=0;i<n;i++)
            {
                if(arr[i]<min && arr[i]!=-1)
                {
                    min = arr[i];
                }
            }
            for(ll i=0;i<n;i++)
            {
                if(arr[i]==min)
                {
                    arr[i] = -(arr[i]+1);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                arr[0] = 0;
        }
        else
        {
            ll min = LONG_MAX;
            for(ll i=0;i<n;i++)
            {
                if(arr[i]<min && arr[i]!=-1)
                {
                    min = arr[i];
                }
            }
            for(ll i=0;i<n;i++)
            {
                if(arr[i]==min)
                {
                    arr[i] = -(arr[i]+1);
                    break;
                    //flag=1;
                }
            }
        }
    }
    for(ll i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}
