#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std; 
int main()
{
	ironman
	string str;
	cin >> str;
	int upper = 0,lower= 0;
	for(int i=0;i<str.length();i++)
	{
		if(islower(str[i]))
			lower++;
		else
			upper++;
	}
	if(upper>lower)
	{
		for(int i=0;i<str.length();i++)
			str[i] = toupper(str[i]);
		cout << str << endl;
	}
	else
	{
		for(int i=0;i<str.length();i++)
			str[i] = tolower(str[i]);
		cout << str << endl;
	}
}
