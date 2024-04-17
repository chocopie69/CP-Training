#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "POWEXP"

using namespace std;

const int INF = INT_MAX, MOD = 1e9+7, LIMIT = 1e5+5;
const ll INFLL = 2e18;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll a,n,m;

ll multi(ll a, ll n, ll m)
{
    if(n == 0) return 0;
    ll cur = multi(a, n/2, m);
    if(n % 2 == 0)
        return (cur + cur) % m;
    return ((cur + cur) % m + a % m) % m;
}

ll power(ll a, ll n, ll m)
{
    if(n == 0) return 1 % m;
    ll cur = power(a,n/2,m);
    if(n % 2 == 0)
        return (multi(cur,cur,m)) % m;
    else
        return multi((multi(cur,cur,m)) % m,a % m, m);
}

int main()
{
    init();
    cin >> a >> n >> m;
    cout << multi(power(a,n,m),power(n,a,m),m);
}


