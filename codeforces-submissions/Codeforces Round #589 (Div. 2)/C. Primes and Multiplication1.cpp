#include<bits/stdc++.h>
using namespace std;
long long x,n;
int num[1000005];
int isprime(long long n)
{
    int flag,i;
    flag=1;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}
long long fastPower(long long base,long long power)
{
    long long result=1;
    while(power>0)
	{
        if(power&1)
		{
            result=result*base%(long long)(1e9+7);
        }
        power>>=1;
        base=(base*base)%(long long)(1e9+7);
    }
    return result;
}
int main()
{
	int cnt=0;
	cin>>x>>n;
	for(int i=2;i*i<=x;i++)
	{
		if(isprime(i) and x%i==0)
		{
			num[cnt++]=i;
		}
		if(isprime(x/i) and x%i==0 and x/i!=i)
		{
			num[cnt++]=x/i;
		}
	}
	if(cnt==0)
	{
		num[cnt++]=x;
	}
	long long ans=0;
	long long res=1;
	for(int i=0;i<cnt;i++)
	{
		long long tmp=n;
		ans=0;
		while(tmp>=num[i])
		{
			tmp/=num[i];
			ans+=tmp;
		}
		res*=fastPower(num[i],ans);
		res%=(long long)(1e9+7);
	}
	cout<<res;
	return 0;
}
