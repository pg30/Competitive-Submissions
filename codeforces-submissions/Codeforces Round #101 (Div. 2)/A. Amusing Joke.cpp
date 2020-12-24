#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	string str1,str2,str3;
	cin >> str1 >> str2 >> str3;
	int arr1[26]={0},arr2[26]={0},arr3[26]={0};
	if(str3.length()!=str1.length()+str2.length())
		cout << "NO" << endl;
	else
	{
		for(int i=0;i<str1.length();i++)
			arr1[str1[i]-65]++;
		for(int i=0;i<str2.length();i++)
			arr2[str2[i]-65]++;
		for(int i=0;i<str3.length();i++)
			arr3[str3[i]-65]++;
		int flag = 1;
		for(int i=0;i<26;i++)
		{
			if(arr3[i]!=arr1[i]+arr2[i])
				flag = 0;
		}
		if(flag==1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
	}
}
