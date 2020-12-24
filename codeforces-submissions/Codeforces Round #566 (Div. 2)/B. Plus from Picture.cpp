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
        ll w,h;
        cin >> w >> h;
        char arr[w][h];
        for(int i=0;i<w;i++)
        {
            for(int j=0;j<h;j++)
            {
                cin >> arr[i][j];
            }
        }
        int flag=0,count=0;
        for(int i=0;i<w;i++)
        {
            for(int j=0;j<h;j++)
            {
                if(arr[i][j]=='.')
                    count++;   
                if(arr[i][j]=='*'&&arr[i][j+1]=='*'&&arr[i][j-1]=='*'&&arr[i-1][j]=='*'&&arr[i+1][j]=='*')
                {
                    flag=1;
                        arr[i][j]='.';
                        ll k = j+1;
                        while(k<h)
                        {
                            if(arr[i][k]=='*')
                            {
                                arr[i][k] = '.';
                                k++;
                            }
                            else
                                break;
                        }
                        k=j-1;
                        while(k>=0)
                        {
                            if(arr[i][k]=='*')
                            {
                                arr[i][k] = '.';
                                k--;
                            }
                            else
                                break;
                        }
                        k=i+1;
                        while(k<w)
                        {
                            if(arr[k][j]=='*')
                            {
                                arr[k][j] = '.';
                                k++;
                            }
                            else
                                break;
                        }
                        k=i-1;
                        while(k>=0)
                        {
                            if(arr[k][j]=='*')
                            {
                                arr[k][j] = '.';
                                k--;
                            }
                            else
                                break;
                        }
                        break;    
                }
            }
            if(flag==1)
                    break;
        }
        flag=0;
        for(int i=0;i<w;i++)
        {
            for(int j=0;j<h;j++)
            {
                if(arr[i][j]=='*')
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1||count==w*h)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
