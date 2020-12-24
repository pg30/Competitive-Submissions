#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
	ironman
	int w,h;
	cin >> w >> h;
	int u1,d1,u2,d2;
	cin >> u1 >> d1 >> u2 >> d2;
	for(int i=h;i>=0;i--)
	{
		w+=i;
		if(i==d1)
			w = w-u1;
		if(w<0)
			w=0;
		if(i==d2)
			w = w-u2;
		if(w<0)
			w=0;
	}
	cout << w << endl;
}
