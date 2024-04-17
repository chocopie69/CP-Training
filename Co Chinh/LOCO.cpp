#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "LOCO"

using namespace std;

const int SZ = 1e7+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,res,dp[SZ];

int main()
{
    init();
    cin >> n >> m;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % m;
        //cout << dp[i] << " " << i << '\n';
    }
    cout << dp[n];
}

