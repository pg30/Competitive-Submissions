#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL ans[6];
int main()
{
    LL x,y;
    LL n;
    LL mod=1000000007;
    while(~scanf("%lld%lld%lld",&x,&y,&n))
    {
        ans[0]=(x%mod+mod)%mod;
        ans[1]=(y%mod+mod)%mod;
        for(int i=2;i<=5;i++)
        {
            ans[i]=(ans[i-1]-ans[i-2])%mod;
            if(ans[i]<0)
                ans[i]+=mod;
        }
        cout << ans[(n-1)%6] <<endl;
    }
    return 0;
}
