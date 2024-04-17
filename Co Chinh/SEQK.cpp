#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "SEQK"

using namespace std;

const int SZ = 5000+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll k,m,n,dp[SZ][SZ], res = 0;

int main()
{
    init();
    cin >> k >> m >> n;
    m--;
    memset(dp,0,sizeof(dp));
    for(int j = 1; j <= m; j++)
    {
        dp[1][j] = 1;
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(j + k <= m)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][j+k]) % MOD;
            }
            if(j - k > 0)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
            }
        }
    }
    for(int j = 1; j <= m; j++)
    {
        res = (res + dp[n][j]) % MOD;
    }
    cout << res;
}
