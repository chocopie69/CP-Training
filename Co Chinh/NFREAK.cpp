#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NFREAK"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX/2, MOD = 20122007, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll a,res = 1;

ll multi(ll a, ll n, ll m)
{
    if(n == 0) return 0;
    ll cur = multi(a, n/2, m);
    cur = (cur + cur) % m;
    if(n % 2 == 0)
        return cur;
    return (cur + a % m) % m;
}

ll power(ll a, ll n, ll m)
{
    if(n == 0) return 1 % m;
    ll cur = power(a,n/2,m);
    cur = multi(cur,cur,m);
    if(n % 2 == 0)
        return cur % m;
    else
        return multi(cur % m,a % m, m);
}

int main()
{
    init();
    cin >> a;
    for(ll d = 1; d * d <= a; d++)
    {
        if(a % d != 0) continue;
        ll m = power(3,d,MOD);
        ll cur = (m == 0 ? MOD-1 : m-1);
        res = multi(res,cur,MOD);
        if(d * d != a)
        {
            ll d1 = a / d;
            m = power(3,d1,MOD);
            cur = (m == 0 ? MOD-1 : m-1);
            res = multi(res,cur,MOD);
        }
    }
    cout << res;
}

