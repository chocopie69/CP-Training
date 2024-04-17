#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "FLOWERS"

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

ll n, sum = 0, res = 0;
pll a[SZ];

bool cmp(pll x, pll y)
{
    return x.fi * y.se < y.fi * x.se;
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        a[i].fi *= 2;
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1; i <= n; i++)
    {
        res += a[i].se*sum;
        sum += a[i].fi;
    }
    cout << res;
}
