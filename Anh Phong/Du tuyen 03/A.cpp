#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

#define TASKNAME "NAME"

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, a[SZ];
ll dp[SZ][10004][3];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i <= n; i++)
    {
        dp[i][0][0] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= 10000; j++)
        {
            dp[i][j][2] = (dp[i][j][2] + dp[i-1][j][2] + dp[i-1][j][1]) % MOD;
            //dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][0]) % MOD;
            if(j + a[i] <= 10000)
            {
                dp[i][j + a[i]][1] = (dp[i][j + a[i]][1] + dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
            }
            dp[i][ abs(j - a[i]) ][1] = (dp[i][ abs(j - a[i]) ][1] + dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
        }
    }
    cout << (dp[n][0][1] + dp[n][0][2]) % MOD;
}