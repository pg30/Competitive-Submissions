#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll int n,count=0;
    cin >> n;
    while(n>0)
    {
        int a = n%10;
        n = n/10;
        if(a==4 || a==7)
            count++;
    }
    if(count==4||count==7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
