#include<bits/stdc++.h>
#define ll long long int
#define ironman ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool prime[101];

ll ncr(ll n, ll k) 
{
  if(k>n)
  	return 0; 
  if (k==0 || k==n) 
    return 1; 
  
  return  ncr(n-1, k-1) + ncr(n-1, k); 
}

void SieveOfEratosthenes(int n) 
{  
    memset(prime, true, sizeof(prime));   
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
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
bool isThreeDisctFactors(long long n) 
{ 
    // Find square root of number 
    int sq = (int)sqrt(n); 
  
    // Check whether number is perfect 
    // square or not 
    if (1LL * sq * sq != n) 
        return false; 
  
    // If number is perfect square, check 
    // whether square root is prime or 
    // not 
    return isPrime(sq) ? true : false; 
}
int main()
{
	ironman
	ll n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin >> a;
		if(isThreeDisctFactors(a))
			cout << "YES" << endl;
		else	
			cout << "NO" << endl;
	}
}
