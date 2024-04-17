#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "VECTO"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n;

ll calc(ll x, ll y)
{
    return x*x+y*y;
}

ll res = 0;

pll dp[SZ], a[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    for(int i = 1; i <= n; i++)
    {
        dp[i] = {a[i].fi,a[i].se};
        for(int j = 1; j < i; j++)
        {
            if(calc(dp[j].fi + a[i].fi, dp[j].se + a[i].se ) > calc(dp[i].fi, dp[i].se))
            {
                dp[i] = {dp[j].fi + a[i].fi, dp[j].se + a[i].se};
            }
        }
        res = max(res, calc(dp[i].fi, dp[i].se));
    }
    cout << res;
}