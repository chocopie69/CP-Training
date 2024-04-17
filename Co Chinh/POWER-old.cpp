#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "POWER"

using namespace std;

const int INF = INT_MAX, MOD = 1e9+7, LIMIT = 1e5+5;
const ll INFLL = 2e18;

void init()
{
    //freopen(TASKNAME".INP","r",stdin);
    //freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll a,n,m;

ll pow2(ll a, ll n, ll m)
{
    if(n == 0) return 1 % m;
    ll cur = pow2(a,n/2,m);
    if(n % 2 == 0)
        return (cur * cur) % m;
    else
        return ( ((cur * cur) % m) * (a % m) ) % m;
}

int main()
{
    init();
    cin >> a >> n >> m;
    cout << pow2(a,n,m);
}

