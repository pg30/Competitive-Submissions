#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	string str1,str2,str3,str4,str5,str6;
	cin >> str1;
	int a=5,flag=0;
	while(a--)
	{
		cin >> str2;
		if(str2[0]==str1[0] || str2[1]==str1[1])
		{
			cout << "YES" << endl;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout << "NO" << endl;
}
