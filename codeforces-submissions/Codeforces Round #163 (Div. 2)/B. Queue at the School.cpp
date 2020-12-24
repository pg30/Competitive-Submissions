#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,t;
	cin >> a >> t;
	char str[a];
	for(int i=0;i<a;i++)
		cin >> str[i];
	while(t--)
	{
		for(int i=0;i<a-1;i++)
		{
			if(str[i]=='B' && str[i+1]=='G')
			{
				char c = str[i];
				str[i] = str[i+1];
				str[i+1] = c;
				i++;
			}
		}
	}
	for(int i=0;i<a;i++)
		cout << str[i];
}
