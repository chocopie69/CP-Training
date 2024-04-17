#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, required[SZ];
ll cost[SZ], dp[SZ][1030];

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < (1 << 10); j++)
        {
            dp[i][j] = -INFLL;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        required[v] |= (1 << (v-u-1));
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < (1 << 10); j++)
        {
            if(dp[i-1][j] == -INFLL) continue;
            int x = ( j & ((1 << 9) - 1) ) << 1, y = x + 1;
            if( (j & required[i]) == required[i] )
            {
                dp[i][y] = max(dp[i][y], dp[i-1][j] + cost[i]);
            }
            dp[i][x] = max(dp[i][x], dp[i-1][j]);
        }
    }
    ll res = 0;
    for(int j = 0; j < (1 << 10); j++)
    {
        res = max(res,dp[n][j]);
    }
    cout << res;
}
