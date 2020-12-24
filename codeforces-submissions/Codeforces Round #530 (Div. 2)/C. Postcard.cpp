#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	string str;
	cin >> str;
	int k,count1=0,count2=0;
	cin >> k;
	int len = str.length();
	int len1 = len;
	for(int i=0;i<len1;i++)
	{
		if(str[i]=='*')
			count1++;
		else if(str[i]=='?')
			count2++;
	}
	len = len-count1-count2;
	//cout << k << " " << len << " " << count1 << " " << count2 << endl;
	if(k==len)
	{
		for(int i=0;i<len1;i++)
			if(str[i]!='*' && str[i]!='?')
				cout << str[i];
	}
	else if(k>len)
	{
		int flag=0;
		if(count1==0)
			cout << "Impossible" << endl;
		else
		{
			for(int i=0;i<len1;i++)
			{
				if(str[i+1]=='*' && flag==0)
				{
					int a = k-len;
					while(a--)
						cout << str[i];
					flag=1;
				}
				if(str[i]!='*' && str[i]!='?')
					cout << str[i];
			}
		}
	}
	else
	{
		int a = len-k;
		if(count1+count2 < a)
			cout << "Impossible" << endl;
		else
		{
			int count = 0;
			for(int i=0;i<len1;i++)
			{
				if(count < a && (str[i+1]=='*'||str[i+1]=='?'))
				{
					count++;
					continue;
				}
				if(str[i]!='*'&&str[i]!='?')
					cout << str[i];
			}
		}
	}
}
