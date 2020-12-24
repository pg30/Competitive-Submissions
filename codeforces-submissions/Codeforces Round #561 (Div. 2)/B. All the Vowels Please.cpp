/*      ###########################
        #  Author : Pranay Garg   #
        #  College : SGSITS       #
        ###########################
*/      
#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
void fastio()
{
    ironman
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
    #endif
}
ll ncr(ll n, ll k) 
{
  if(k>n)
    return 0; 
  if (k==0 || k==n) 
    return 1; 
  
  return  ncr(n-1, k-1) + ncr(n-1, k); 
}
bool prim[5005];vector<ll> prime;
void sieve(int n) 
{  
    memset(prim, true, sizeof(prime));   
    for (int p=2; p*p<=n; p++) 
    { 
        if (prim[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prim[i] = false; 
        } 
    }
    for(int i=2;i<=n;i++)
    {
        if(prim[i]==true)
            prime.push_back(i);
    }
}

bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
      for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}
bool powerOfTwo(int n)
{
    return (n&!(n&(n-1)));
}
int countone(int n)
{
    int count=0;
    while(n)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}
bool checkibit(ll n, ll i)
{
    if (n & (1 << (i - 1))) 
        return true;
    else
        return false;
}
ll factorial(ll n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
}
int main()
{
    fastio();
    int k;
    cin >> k;
    if(k<25)
        cout << -1 << endl;
    else
    {
        char arr[5][5] = {{'a','e','i','o','u'},{'e','i','o','u','a'},{'i','o','u','a','e'},{'o','u','a','e','i'},{'u','a','e','i','o'}};
        int flag = 0;
        for(int i=5;i<k;i++)
        {
            if(k%i==0)
            {
                int a = k/i;
                if(a>=5)
                {
                    int rows = i-5,columns = a-5;
                    char vec[] = {'a','e','i','o','u'};
                    int b = 0;
                    for(int i=0;i<5;i++)
                    {
                        for(int j=0;j<5;j++)
                        {
                            cout << arr[i][j];
                        }
                        for(int j=0;j<columns;j++)
                        {
                            cout << vec[b];
                        }
                        b++;
                        b = b%5;
                    }
                    
                    for(int i=0;i<rows;i++)
                    {
                        b = 0;
                        for(int j=0;j<a;j++)
                        {
                            cout << vec[b];
                            b++;
                            b = b%5;
                        }
                    }
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0)
            cout << -1 << endl;
        else
            cout << endl;
    }
}
