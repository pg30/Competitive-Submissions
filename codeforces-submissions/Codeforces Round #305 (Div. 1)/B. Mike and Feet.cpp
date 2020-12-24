#include <bits/stdc++.h>
using namespace std;
int ans[1000000],ii,ab[1000000],tas,x,n,a[1000000],aa[1000000];
int main() {
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>a[i];
  }
  for (int i=1;i<=n+1;i++){
    x=0;

    while(tas){
      if (a[i]>aa[tas]) break;
      ii=x+ab[tas];
      if (aa[tas]>ans[ii]) ans[ii]=aa[tas];
      x+=ab[tas];
      tas--;
    }
    tas++;

    ab[tas]=x+1;
    aa[tas]=a[i];
    
  }
  for (int i=n-1;i>=1;i--){
    ans[i]=max(ans[i],ans[i+1]);
  }
  for (int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }

}
