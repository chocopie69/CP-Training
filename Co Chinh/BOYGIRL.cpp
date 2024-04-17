#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "BOYGIRL"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n,m;

ll factorial(ll n, ll m)
{
    ll res = 1;
    for(ll i = 1; i <= n; i++)
    {
        res = (res * i) % m;
    }
    return res;
}

ll multi(ll a, ll n, ll m)
{
    if(n == 0) return 0;
    ll cur = multi(a, n/2, m);
    if(n % 2 == 0)
        return (cur + cur) % m;
    return ((cur + cur) % m + a % m) % m;
}

int main()
{
    init();
    cin >> n >> m;
    if(abs(n-m) > 1)
    {
        cout << 0;
    }
    else if(n == m)
    {
        cout << (multi(factorial(n,MOD),factorial(m,MOD),MOD) * 2) % MOD;
    }
    else
    {
        cout << multi(factorial(n,MOD),factorial(m,MOD),MOD);
    }
}

