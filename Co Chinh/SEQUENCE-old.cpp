#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "SEQUENCE"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll x, n, m;

ll power(ll a, ll b)
{
    if(b == 0) return 1;
    ll cur = power(a,b/2);
    cur = (cur*cur) % m;
    if(b % 2 == 1)
    {
        return (cur * (a % m)) % m;
    }
    return cur;
}

ll f(ll i)
{
    if(i == 0) return 1;
    //cout << i << " " << j << " " << k << '\n';
    if(i % 2 == 1)
        return ((1 + power(x,(i+1)/2) % m) * f(i/2) ) % m;
    return (f(i-1) + power(x,i)) % m;
}

int main()
{
    init();
    cin >> x >> n >> m;
    cout << f(n) << '\n';
}



