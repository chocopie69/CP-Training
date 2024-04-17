#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "STACK"

using namespace std;

const int SZ = 2500+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, dp[SZ][SZ];
pll a[SZ];

bool cmp(pll x, pll y)
{
    return y.se - x.fi > x.se - y.fi;
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].se;
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 0; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = INFLL;
        }
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(dp[i-1][j-1] <= a[i].se) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + a[i].fi);
        }
    }
    for(int j = n; j >= 1; j--)
    {
        if(dp[n][j] != INFLL)
        {
            cout << j;
            break;
        }
    }
}
