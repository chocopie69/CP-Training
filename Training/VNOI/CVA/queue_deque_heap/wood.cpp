#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 20002;
int t,n;
ll a,res=0;
priority_queue<ll,vector<ll>,greater<ll>> pq;

int main()
{
    cin >> t;
    while(t--)
    {
        res=0;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> a;
            pq.push(a);
        }
        while(pq.size() >= 2)
        {
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            pq.push(x+y);
            res += x+y;
        }
        cout << res << '\n';
        pq.pop();
    }
}
