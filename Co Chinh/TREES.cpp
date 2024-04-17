#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "TREES"

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

ll n, res = 0;
pll a[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    a[n+1] = a[1];
    for(int i = 2; i <= n+1; i++)
    {
        ll x = abs(a[i].fi - a[i-1].fi), y = abs(a[i].se - a[i-1].se);
        res += __gcd(x,y) - 1;
        //cout << x << " " << y << " " << __gcd(x,y) - 1;
    }
    cout << res + n;
}
