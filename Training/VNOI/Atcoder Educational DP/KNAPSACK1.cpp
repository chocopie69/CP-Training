#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 100+5, SZ2 = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,w, dp[SZ][SZ2];
pll a[SZ];

int main()
{
    init();
    cin >> n >> w;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    for(int j = 1; j <= w; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            dp[i][j] = dp[i-1][j];
            if(a[i].fi <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i].fi] + a[i].se);
        }
    }
    cout << dp[n][w];
}
