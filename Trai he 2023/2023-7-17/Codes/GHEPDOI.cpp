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

const int SZ = 22;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,a[SZ][SZ],dp[1 << SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    dp[0] = 1;
    for(int mask = 1; mask < (1 << n); mask++)
    {
        int x = __builtin_popcount(mask);
        for(int i = 1; i <= n; i++)
        {
            if(mask >> (i-1) & 1 && a[i][x] == 1)
            {
                dp[mask] = (dp[mask] + (dp[mask - (1 << (i-1)) ] % MOD)) % MOD;
            }
        }
    }
    cout << dp[ (1 << n) - 1 ];
}
