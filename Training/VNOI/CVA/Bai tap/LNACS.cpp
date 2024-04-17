#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int m,n,a[LIMIT],b[LIMIT],dp[LIMIT][LIMIT], res = 0;

int main()
{
    init();
    cin >> m >> n;
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        dp[1][i] = int(dp[1][i-1] == 1 || b[i] == a[1]);
        dp[2][i] = int(dp[2][i-1] == 1 || b[i] == a[1] || b[i] == a[2]);
        res = max({res,dp[1][i],dp[2][i]});
    }
    for(int i = 1; i <= m; i++)
    {
        dp[i][1] = int(dp[i-1][1] == 1 || a[i] == b[1]);
        dp[i][2] = int(dp[i-1][2] == 1 || a[i] == b[1] || a[i] == b[2]);
        res = max({res,dp[i][1],dp[i][2]});
    }
    for(int i = 3; i <= m; i++)
    {
        for(int j = 3; j <= n; j++)
        {
            dp[i][j] = max({ dp[i][j-1], dp[i-1][j], dp[i-2][j-2] + (a[i] == b[j]) });
            res = max(res,dp[i][j]);
        }
    }
    cout << res;
}

