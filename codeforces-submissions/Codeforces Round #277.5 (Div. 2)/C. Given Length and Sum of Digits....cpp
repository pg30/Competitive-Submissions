#include<bits/stdc++.h>
using namespace std;
#define max1 100001
#define mod 1000000007
#define ll long long int
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll i,j,k,n,m,t,x,y,z,d=0,s=0,l,r,ch,k1,k2,k3,s1=0,s2=0,z1,q;
  cin>>m>>n;
  if(n>0)
  {
    s=n;
    vector<ll> a(m,0);
    if(s>0)
    {
      a[0]=1;
      s--;
    }
    for(i=m-1;i>=0;i--)
    {
      if(s>=9&&i>0)
      {
        a[i]+=9;
        s=s-9;
      }
      else if(s>0&&s<9)
      {
        a[i]+=s;
        s=0;
      }
    }
    if(s<=0)
    {
      for(i=0;i<m;i++)
      {
        cout<<a[i];
      }
    }
    else
    {
      cout<<-1;
    }
    cout<<" ";
    s=n;
    for(i=0;i<m;i++)
    {
      if(s>9)
      {
        a[i]=9;
        s=s-9;
      }
      else if(s>0)
      {
        a[i]=s;
        s=0;
      }
      else
      {
        a[i]=0;
      }
    }
    if(s<=0)
    {
      for(i=0;i<m;i++)
      {
        cout<<a[i];
      }
    }
    else
    {
      cout<<-1;
    }
  }
  else if(n==0&&m==1)
  {
    cout<<0<<" "<<0;
  }
  else
  {
    cout<<-1<<" "<<-1;
  }
}
