#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
    int q,w,e,r,n,i,b,c,j,flag=0;
    cin>>n;
    vector <pair <int, int > > a;
    for (i=0;i<n;i++)
    {
        cin>>b>>c;
        a.pb(mp(b,c));
    }
    for (i=0;i<n;i++)
    {
        q=0,w=0,e=0,r=0;
        for (j=0;j<n;j++)
        {
            if (a[j].second>a[i].second && a[j].first==a[i].first)
                q=1;
            if (a[j].second<a[i].second && a[j].first==a[i].first)
                w=1;
            if (a[j].second==a[i].second && a[j].first>a[i].first)
                e=1;
            if (a[j].second==a[i].second && a[j].first<a[i].first)
                r=1;
        }
        if (q && w && e && r)
            flag++;
    }
    cout<<flag;
    return 0;
}
