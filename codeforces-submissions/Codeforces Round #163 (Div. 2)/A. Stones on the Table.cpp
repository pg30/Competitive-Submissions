#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std; 
int main()
{
	ironman
	int n;
	cin >> n;
	string str;
	cin >> str;
	int count = 0;
	for(int i=0;i<str.length()-1;i++)
	{
		if(str[i]==str[i+1])
			count++;
	}
	cout << count << endl;
}
