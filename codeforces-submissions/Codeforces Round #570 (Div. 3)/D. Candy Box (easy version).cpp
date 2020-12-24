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
ll suma(ll n)
{
    ll temp = n;
    ll sum1 = 0;
    //cout << temp << endl;
    while(temp!=0)
    {
        sum1+=(temp%10);
        temp = temp/10;
    }
    return sum1;
}
int main()
{
    fastio();
    ll q;
    cin >> q;
    while(q--)
    {
        ll n;
        cin >> n;
        unordered_map<ll,ll> mp,count;
        std::vector<ll> arr(n);
        for(ll i=0;i<n;i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        priority_queue<ll> pq;
        for(auto it=mp.begin();it!=mp.end();it++)
            pq.push(it->second);
        ll sum = 0;
        while(!pq.empty())
        {
            if(count[pq.top()]==0)
            {
                count[pq.top()]++;
                //cout << pq.top() << " ";
                sum+=pq.top();
                pq.pop();
            }
            else
            {
                ll temp = pq.top();
                pq.pop();
                if(temp>1)
                pq.push(temp-1);
            }
        }

        cout << sum << endl;
    }
}
